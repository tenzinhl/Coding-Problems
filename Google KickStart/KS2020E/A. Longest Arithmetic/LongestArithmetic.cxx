#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9

void solve() {
	int n;
	cin >> n;
	int a, b;
	cin >> a >> b;
	int curcnt;
	curcnt = 2;
	int ans = 2;
	int c;
	for (int i = 2; i < n; i++) {
		cin >> c;
		if (c - b == b - a) {
			curcnt += 1;
			ans = max(ans, curcnt);
		} else {
			curcnt = 2;
		}
		a = b;
		b = c;
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

