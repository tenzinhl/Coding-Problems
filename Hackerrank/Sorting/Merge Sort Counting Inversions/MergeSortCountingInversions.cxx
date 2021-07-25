#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9

long long inversionCount; // global variable to keep track of numbers of inversions.
vector<int> mergedVector;

void mergeSections(vector<int> &v, int b, int e) {
	int mid = (b + e) / 2;
	int left = b, right = mid + 1;
	mergedVector.clear(); // If this takes N time, then you end up having N^2 complexity... nvm, since every element would be pushed to and deleted from mergeVector log(n) times for overall NlogN, which is same as before
	while (left <= mid and right <= e) {
		if (v[right] < v[left]) {
			// number of objects in the left section = mid - left + 1;
			mergedVector.push_back(v[right]);
			right++;
			inversionCount += mid - left + 1;
		} else {
			mergedVector.push_back(v[left]);
			left++;
		}
	}
	while (left <= mid) {
		mergedVector.push_back(v[left]);
		left++;
	}
	while (right <= e) {
		mergedVector.push_back(v[right]);
		right++;
	}
	// copy contents of sorted mergedSections into original vector.
	for (int i = 0; i < mergedVector.size(); i++) {
		v[i + b] = mergedVector[i];
	}
	return;
}

// 0-based indexing for b and e.
void mergeSort(vector<int> &v, int b, int e) {
	if (b >= e) return;
	int mid = (b + e) / 2; // left leaning (not necessarily, 1 2 3 4 5 will lean left, 0 1 2 3 4 will lean right
	mergeSort(v, b, mid);
	mergeSort(v, mid + 1, e);
	mergeSections(v, b, e);
	return;
}
long countInversions(vector<int> arr) {
	inversionCount = 0;
	mergeSort(arr, 0, arr.size() - 1);
	return inversionCount;
}

vector<int> inputVector;
int main()
{
	ifstream stin("input.txt");
	int t;
	for (int i = 0; i < t; i++) {
		int n;
		stin >> n;
		for (int j = 0; j < n; j++) {
			
		}
		cout << "testcase #" << t << ": ";
	}
	return 0;
}

/* KEY TAKEAWAYS: 
 * When calculating time complexity, I have to be careful about proportionality.
 * Here for example, in mergeSections(), I treated iterating over everything in
 * in the range of the merge as proportional to N (which it is in someways), but
 * then multiplied that by N (since mergeSections has to be run proportional to N
 * times), forgetting to account for the fact every layer gets exponentially smaller.
 * 
 * I had the same issue when calculating the time complexity for Bellman-Ford algorithm
 * in that Kickstart problem. While on average the number of connections a node has
 * will be proportional to # of edges, in one loop, you only visit every edge twice,
 * so it's not V * E, it's V + E.*/

/* LOL, I passed all sample test cases on first try, and I was about to frikking freak out.
 * HOLD UP, this has stumped me for 15-20 minutes, and I think this WHOLE TIME it might've
 * been overflow. HOLY CARP IT WAS GODDAMN THIS S*** F*** CRAP8OJSDKJFNSDLKFSD;KDFJ. Yeah,
 * WELL GREAT JOB. Actually though, that's so fing huge. You did GREAT TENZIN. THATS BASICALLY
 * A FIRST TRY. You haven't done this in a while so forgot to check for overflow first,
 * but we solved it! GOOD JOB.*/
