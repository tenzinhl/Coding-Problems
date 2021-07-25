#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9

// Complete the activityNotifications function below.
int activityNotifications(vector<int> expenditure, int d) {
	multiset<int> lowerHalf;
	multiset<int> upperHalf;
	vector<int> curSet;
	for (int i = 0; i < d; i++) {
		curSet.push_back(expenditure[i]);
	}
	sort(curSet.begin(), curSet.end());
	
	for (int i = 0; i < d/2; i++) {
		lowerHalf.insert(curSet[i]);
	}
	
	for (int i = d/2; i < d; i++) {
		upperHalf.insert(curSet[i]);
	}
	
	long double median;
	int curValue;
	int warnCount = 0;
	for (int i = d; i < expenditure.size(); i++) {
		if (d%2 == 0) {
			median = ((long double)*lowerHalf.rbegin() + *upperHalf.begin()) / 2;
		} else {
			median = *upperHalf.begin();
		}
		curValue = expenditure[i];
		if (curValue >= median * 2) {
			warnCount += 1;
		}
		// cout << "Median: " << median << endl;
		int &oldValue = expenditure[i-d];
		// Now we delete old value from one of the sets, add new value, and shift sets around so they are balanced again.
		if (lowerHalf.count(oldValue)) {
			lowerHalf.erase(lowerHalf.find(oldValue));
		} else {
			upperHalf.erase(upperHalf.find(oldValue));
		}
		
		// This was causing OOB, or Segmentation fault as I've learned it's supposed to be called.
		// Instead we should check against upperHalf, since even if d == 1, upperHalf will be the
		// one that contains at least one value... nvm. We need to check that.;
		if (upperHalf.size() == 0) {
			upperHalf.insert(curValue);
		} else if (curValue <= *upperHalf.begin()) {
			lowerHalf.insert(curValue);
		} else {
			upperHalf.insert(curValue);
		}
		
		int temp;
		while (lowerHalf.size() > upperHalf.size()) {
			temp = *lowerHalf.rbegin();
			lowerHalf.erase(lowerHalf.find(temp));
			upperHalf.insert(temp);
		}
		while (upperHalf.size() > lowerHalf.size() + 1) {
			temp = *upperHalf.begin();
			upperHalf.erase(upperHalf.begin());
			lowerHalf.insert(temp);
		}
	}
	return warnCount;
}

int main()
{
	int n, d;
	cin >> n >> d;
	vector<int> input;
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		input.push_back(temp);
	}
	// cout << "WarnCount: " << activityNotifications(input, d);
	return 0;
}
/*
5 4
1 2 3 4 4 

5 3
10 20 30 40 50
*/
/* So I have some ideas. First, is to maintain a multiset which we populate
 * with the first d values. Then, we get an iterator to the middle. Then
 * as we push new value and remove old one each iteration, and based on
 * sizes of values removed and added, we either increment, decrement, or don't
 * move the iterator to find the median of our past couple days. (Credit to
 * some guy on StackOverflow, brilliant idea). Need to be careful though,
 * if the iterator is currently pointing to the next item to be removed, there'll
 * need to be some special maneuvering.
 * 
 * Other idea is to keep sorting vector as we push values... but that would give
 * us O(N * dlog(d)) which is much too high. I think we implement first idea, and
 * then check editorial after.
 * */
 
/* So recently I checked out heaps as a potential solution to this problem, however
 * they do not guarantee the ordering of the elements besides the top one, so... that
 * was no help (since median could be in variable positions). The issue with using the
 * multiset solution arises when we have to delete and insert the element that the median
 * iterator is currently pointing to. I think I can handle deletion by moving one off
 * the iterator before deleting it, but for insertion, it seems like the C++ standard
 * does not specify where an equivalent key will be inserted... So I don't know whether
 * it'll be above or below the current median value.
 * 
 * Ooh! How about map, where associated value is the index of the lower bound for that
 * given value. That might actually be doable. nvm, keeping track of that index would 
 * require updating a whole bunch of keys when you delete or insert. What about the number
 * of each? But then how do we access median in constant time?
 * 
 * GOODDDDAMMNNNN THATS SMART HOWD I NOT THINK OF IT SHIIIIITTTTT. I looked up "sliding window
 * median" on leetcode, and the solution is so simple I feel FRIKKING STUPID.
 * So we have to use sets, duh. We need constant access time to median, duh. What
 * can you access in constant time in a set? The beginning or end! SO:
 * If you just split your sliding window into two sets, you can access the beginning
 * of the 2nd or the end of the 1st in constant time to find the median. On insertion
 * you only need to make a maximum of three moves (insert new, delete from overloaded set,
 * move the deleted value to other set). GOD IT's SO INGENIUS I FEEL FRIKKING SO STUPID
 * GODDS FADFJSADL;KFJSD;LKFJS;DLKFJ.*/
 
 /* Nice job! We did this one after like 35 mins. Sept. 19, 2020.
  * Key takeaways: 
  * Whenever you have to have one variable that's long long
  * or double and it's being calculated from ints (or any other simple type)
  * YOU MUST TYPE CAST somewhere in the equation to get the right result! (Usually
  * typecast near the start, as it will then cascade down the other calculations.)
  * 
  * OOB Access, which I now know is Segmentation fault, is almost always an issue.*/
