#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9

const int LIM = (int) 1e5 + 8;
int n;
string a;
int dp[LIM];
void solve() {
	cin >> n;
	int sum = 0;
	int si = 0;
	cin >> a;
	int cur;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		cur = a[i] - '0' - 1;
		sum += cur;
		if (sum == 0) {
			dp[i] = dp[max(si - 1, 0)] + 1;
			si = i + 1;
			ans += dp[i];
		}
		cout << sum << endl;
	}
	
	cout << ans << "\n";
	memset(dp, 0, n * sizeof(int));
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		solve();
	}
	return 0;
}
/*
1
5
11011
* */
