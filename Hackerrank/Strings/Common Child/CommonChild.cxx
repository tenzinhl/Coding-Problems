#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9

int dp[5008][5008];
int commonChild(string s1, string s2) {
	memset(dp,0, sizeof(dp));
	for (int i = 0; i <= 5002; i++) {
		dp[i][0] = 0;
		dp[0][i] = 0;
	}
	for (int i = 1; i <= s1.size(); i++) {
		for (int j = 1; j <= s2.size(); j++) {
			if (s1[i-1] == s2[j-1]) {
				dp[i][j] = dp[i-1][j-1] + 1;
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	return dp[s1.size()][s2.size()];
}

int main()
{
	return 0;
}

/* I guess I'm a little disappointed I just looked at the discussion to find
 * a wikipedia link that explains the solution. I'm also disappointed I wasn't
 * able to see that the problem had optimal substructure and overlapping subproblems.
 * i.e.: I'm kind of disappointed that I didn't figure out it was a DP problem.
 * But whatever, I'm really tired, and I'll just implement it and go to sleep.
 * 
 * once again, tbf, I'm really tired today for some reason, and also I haven't
 * done a DP problem in a long while.
 * 
 * Wowza we did it. Nice job Tenzin!*/
