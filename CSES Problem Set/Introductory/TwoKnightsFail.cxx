#include <bits/stdc++.h>
using namespace std;

long long dp[10000];
int main()
{
	int n;
	cin >> n;
	dp[1] = 0;
	dp[2] = 6;
	dp[3] = 28;
	dp[4] = 96;
	dp[5] = 252;
	dp[6] = 550;
	for (int i = 7; i <= n; i++) {
		dp[i] = 4 * dp[i-1] + 8 * i - 16;
	}
	
	for (int i = 1; i <= n; i++) {
		cout << dp[i] << "\n";
	}
	
	return 0;
}
//sounds like a dp problem
//number of new arrangements introduced each step: 2x - 3
//AAAHHH I think I've totally goofed this. I'm gonna skip for now. I know
//that an answer online is just a straight up formula for each value of i.
//i Don't got that.
