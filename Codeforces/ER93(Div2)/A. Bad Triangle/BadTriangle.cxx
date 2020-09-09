#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9
#define LIM (int) 5e4 + 8
int n, a[LIM];
// deque<int> cur;
void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	if (a[0] + a[1] <= a[n-1]) {
		cout << 1 << ' ' << 2 << ' ' << n << "\n";
	} else {
		cout << -1 << "\n";
	}
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

