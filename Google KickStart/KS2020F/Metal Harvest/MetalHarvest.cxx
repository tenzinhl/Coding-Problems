#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9
#define LIM (int) 1e5 + 8
int s[LIM], e[LIM];
pair<int, int> intervals[LIM];
void solve() {
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> s[i] >> e[i];
		intervals[i] = make_pair(s[i], e[i]);
	}
	sort(intervals, intervals+n);
	int spareEndTime = 0;
	int start, end;
	int ans = 0;
	int curRobots;
	for (int i = 0; i < n; i++) {
		start = max(spareEndTime, intervals[i].first);
		end = intervals[i].second;
		if (start >= end) {
			continue;
		}
		curRobots = (end - start - 1) / k + 1;
		ans += curRobots;
		spareEndTime = start + curRobots * k;
		// cout << "currobots: " << curRobots << endl;
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

