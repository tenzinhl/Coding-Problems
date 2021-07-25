#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9

int luckBalance(int k, vector<vector<int>> contests) {
	vector<int> luckOfImportantContests;
	int luckBalance = 0;
	for (int i = 0; i < contests.size(); i++) {
		if (contests[i][1]) {
			luckOfImportantContests.push_back(contests[i][0]);
		} else {
			luckBalance += contests[i][0];
		}
	}
	
	sort(luckOfImportantContests.begin(), luckOfImportantContests.end(), greater<int>());
	int i = 0;
	while (k > 0 and i < luckOfImportantContests.size()) {
		luckBalance += luckOfImportantContests[i];
		k--;
		i++;
	}
	while (i < luckOfImportantContests.size()) {
		luckBalance -= luckOfImportantContests[i];
		i++;
	}
	return luckBalance;
}

// Noice.
int main()
{
	return 0;
}

