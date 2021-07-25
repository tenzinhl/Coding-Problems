#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9
#define LIM (int) 1e5 + 8
int e[LIM], r[LIM];
int p[LIM];
void solve() {
	int n;
	long long ttime = 0;
	for (int i = 0; i < n; i++) {
		cin >> e[i] >> r[i];
		p[i] = make_pair(r[i], e[i]);
		ttime += e[i];
	}
	// Ri + Ei <= Total Time (Derived from Total time - Ei >= Ri)
	sort(p, p + n, greater<int>);
	int i;
	for (i = 0; i < n; i++) {
		if (p[i].first > ttime - p[i].second) {
			ttime -= p[i].second;
		} else {
			cout << i << " " << "INDEFINITELY" << "\n";
		}
	}
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

