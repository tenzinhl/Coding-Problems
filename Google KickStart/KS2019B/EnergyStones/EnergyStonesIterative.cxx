#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define N 108
int n, s[N], e[N], l[N];
int o[N];

bool cmp(int x, int y) {
	int a = e[x] + e[y] - s[x] * l[y];
	int b = e[x] + e[y] - s[y] * l[x];
	return a > b;
}

ll dp[20008], odp[20008];
void solve() {
	cin >> n;
	memset(o, 0, sizeof(o));
	for (int i = 0; i < n; i++) {
		cin >> s[i] >> e[i] >> l[i];
		o[i] = i;
	}
	
	sort(o, o + n, cmp);
	
	memset(dp, 0, sizeof(dp));
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int ind = o[i];
		sum += s[ind];
		for (int k = 0; k <= sum; k++) {
			odp[k] = dp[k];
		}
		for (int t = s[ind]; t <= sum; t++) {
			int ep = e[ind] - ((t - s[ind]) * l[ind]);
			if (ep <= 0) {
				break;
			} else {
				dp[t] = max(dp[t], odp[t - s[ind]] + ep);
			}
		}
	}
	
	ll ans = 0;
	for (int i = 0; i <= sum; i++) {
		ans = max(ans, dp[i]);
	}
	cout << ans << "\n";
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}

