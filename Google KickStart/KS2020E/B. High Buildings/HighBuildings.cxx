#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9

int n, a, b, c;
void solve() {
	cin >> n >> a >> b >> c;
	if (a + b - c > n or (a + b == 2 and c == 1 and n > 1)) {
		cout << "IMPOSSIBLE" << "\n";
		return;
	}
	int l, r, mid, fill;
	l = a - c;
	r = b - c;
	mid = c;
	fill = n - l - r - mid;
	if (l == 1 and n > 2) {
		cout << 2 << " ";
	} else {
		for (int i = 1; i <= l; i++) {
			cout << i << " ";
		}
	}
	bool filled = false;
	if (l >= 1) {
		for (int i = 0; i < fill; i++) {
			cout << 1 << " ";
		}
		filled = true;
	}
	for (int i = 0; i < mid; i++) {
		cout << n << " ";
		if (i == 0 and mid > 1 and filled == false) {
			for (int j = 0; j < fill; j++) {
				cout << 1 << " ";
			}
			filled = true;
		}
	}
	if (filled == false) {
		for (int i = 0; i < fill; i++) {
			cout << 1 << " ";
		}
	}
	int t = n - 1;
	for (int i = 0; i < r; i++) {
		cout << t << " ";
		t -= 1;
	}
	cout << "\n";
	return;
}
// C buildings they can both see must all be of same height.
// Since lim is so small, is it possible to do backtracking?
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

/*
1
5 4 4 3
 * */
