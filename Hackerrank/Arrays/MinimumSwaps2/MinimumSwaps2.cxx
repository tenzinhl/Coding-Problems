#include <bits/stdc++.h>
using namespace std;

int minimumSwaps(vector<int> arr) {
    // vals are 1 through 10^5, so -1 to get corresponding index
    int init = arr[0];
    bool chkd[(int) 1e5 + 8] = {true};
    const int n = arr.size();
    int chkdTotal = 1;
    int curIndex, curVal = arr[0];
    int jmps = 0;
    int totalJmps = 0;
    int hole = n - 1;
    while (chkdTotal < n) {
        curIndex = curVal - 1;
        curVal = arr[curIndex];
        if (curVal == curIndex + 1) {
					chkdTotal += 1;
					chkd[curVal] = true;
					while (chkd!
				}
        jmps += 1;
        chkdTotal += 1;
        chkd[curIndex] = true;
        if (!chkd[curVal - 1]) {
            hole = min(hole, curVal - 2);
        }
        if (!chkd[curVal + 1]) {
            hole = min(hole, curVal);
        }
        if (curVal == init) {
            totalJmps += jmps;
            jmps = 0;
            curVal = hole; // Set our next Index to be the lowest earliest "hole"
            chkd[hole] = true;
            chkdTotal += 1;
            hole = n - 1;
        }
    }
    return totalJmps;
}

int main() {
	vector<int> v;
	int n;
	cin >> n;
	int t;
	for (int i = 0; i < n; i++) {
		cin >> t;
		v.push_back(t);
	}
	
	cout << minimumSwaps(v);
	return 0;
}
/* Takeaway 
 * Was kind of scatterbrained on this one. Forgot to write code to account for when
 * a number is in the position it is supposed to be.*/
 
/* Okay, so issue I'm currently running into is time complexity when handling numbers
 * that are in the right spot. After I fill the hole, if I just iterate forward to
 * find the next unchecked index, I think that might give a worst case of n^2, (think
 * of a structure where you fill a hole, and that is encapsulated in another one of those)
 * How do I get back on track?
 * 
 * As I was thinking I wondered if keeping track of two holes would work, but I don't think
 * it would. I should just maintain a priority queue of unchec*/
/*
5
2 3 1 5 4
7
1 3 5 2 4 6 7
*/
