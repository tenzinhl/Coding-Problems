#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9
#define LIM 1008
int n, k;
int p[LIM], a[LIM];
pair<int, int> pa[LIM];
vector<int> dist[LIM];
int dp[LIM][LIM];
void solve() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	for (int i = 0; i < n; i++) {
		pa[i] = make_pair(p[i], a[i]);
	}
	
	sort(pa, pa + n);
	
	int pt, at;
	for (int i = 0; i < n; i++) {
		pt = pa[i].first;
		at = pa[i].second;
		dist[at].push_back(pt);
	}
	
	memset(dp, 127, sizeof(dp));
	dp[0][0] = 0;
	int cnt = 0, ans = INF;
	for (int i = 1; i < LIM; i++) {
		dp[i][0] = 0;
		for (int j = 0; j < dist[i].size() + cnt and j < k; j++) {
			dp[i][j] = dp[i-1][j];
			for (int z = 0; z < dist[i].size() and z <= j - 1; z++) {
					dp[i][j] = min(dp[i][j], dp[i-1][j-z] + dist[i][z] * 2);
					if (j == k) {
						ans = min(ans, dp[i-1][j-z] + dist[i][z]);
					}
			}
		}
		cnt += dist[i].size();
	}
	
	for (auto &v : dist) {
		v.clear();
	}
	cout << ans << "\n";
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

