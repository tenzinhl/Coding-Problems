//Tenzin Low
//
#include <bits/stdc++.h>
using namespace std;

//don't forget global arrays get elements init to 0 (or whatever default
//for that type is)
int n, k, p, a[51][31];
int sum[51][31];
int dp[51][1501];

//Solves for the maximum beauty value possible
//through memoization of max beauty for j plates
//from the first i stacks.
int solve() {
	cin >> n >> k >> p; //n is number of stacks, k plates per stack, p plates to take.
	
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=k; j++) {
			cin >> a[i][j];
			sum[i][j] = sum[i][j-1] + a[i][j]; //need to check if this works for j=0;
			//figured out solution: give sum one more column(row?),
			//it will be init to 0.
		}
	}
	
	
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=p; j++) {
			dp[i][j]=0;
			for (int z=0; z<=k and z<=j; z++) {
				dp[i][j] = max(dp[i][j],sum[i][z]+dp[i-1][j-z]);
			}
		}
	}
	
	return dp[n][p];
}
	
int main (){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	for (int i = 1; i<= t; i++){
		cout << "Case #" << i << ": ";
		cout << solve() << "\n";
	} 
	return 0;
}
