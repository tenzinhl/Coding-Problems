#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define LIM 100008

int n, q, cnt[26][LIM];
void solve() {
	cin >> n >> q;
	char cur;
	for (int i = 1; i <= n; i++) {
		cin >> cur;
		for (int j = 0; j < 26; j++) {
			if (cur - 'A' == j) {
				cnt[j][i] = cnt[j][i-1] + 1;
			} else {
				cnt[j][i] = cnt[j][i-1];
			}
		}
	}
	
	int possible = 0;
	int odd = 0;
	int l, r, z;
	for (int i = 0; i < q; i++) {
		cin >> l >> r;
		for (int j = 0; j < 26; j++) {
			z = cnt[j][r] - cnt[j][l-1];
			if (z % 2 != 0) {
				odd += 1;
			}
		}
		if (odd <= 1) {
			possible += 1;
		}
		odd = 0;
	}
	
	cout << possible << "\n";
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

// good job, I can feel that I'm getting smoother at this.
