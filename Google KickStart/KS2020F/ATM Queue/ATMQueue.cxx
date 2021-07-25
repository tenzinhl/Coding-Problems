#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9

pair<int, int> pos[(int) 1e5 + 8];
void solve() {
	int n, x;
	cin >> n >> x;
	int a;
	int times;
	for (int i = 0; i < n; i++) {
		cin >> a;
		times = (a - 1) / x + 1;
		pos[i] = make_pair(times, i);
	}
	sort(pos, pos + n);
	for (int i = 0; i < n; i++) {
		cout << pos[i].second + 1 << " ";
	}
	cout << endl;
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

