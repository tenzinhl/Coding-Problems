#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9

vector<int> freqQuery(vector<vector<int>> queries) {
	unordered_map<int, int> numCount;
	unordered_map<int, int> freqCount;
	vector<int> ans;
	int type, val, freq;
	for (int i = 0; i < queries.size(); i++) {
		type = queries[i][0];
		val = queries[i][1];
		if (type == 1) {
			numCount[val] += 1;
			freq = numCount[val];
			if (freq != 1) {
				freqCount[freq - 1] -= 1;
			}
			freqCount[freq] += 1;
		} else if (type == 2) {
			if (numCount[val] > 0) {
				numCount[val] -=1;
				freq = numCount[val];
				if (freq > 0) {
					freqCount[freq] += 1;
				}
				freqCount[freq + 1] -= 1;
			}
		} else if (type == 3) {
			if (freqCount[val] > 0) {
				ans.push_back(1);
			} else {
				ans.push_back(0);
			}
		}
	}
	return ans;
}

int main()
{
	return 0;
}

/* WAIt. Lol,both of my .push_back() statements were pushing 0. ALSO, how did
 * only one test case test reducing a frequency from 1 to 0, like what. I only failed
 * that one lol. Anyways, I fixed the broken logic then moved on. TBH, kind of sad
 * that I made that error as I went along, especially since I had the logic all right
 * in when adding a number, so I should've easily been able to reverse the logic
 * for removing a number. Whatever, we submitted successfully.*/
