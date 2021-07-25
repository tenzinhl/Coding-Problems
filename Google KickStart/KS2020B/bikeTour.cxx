#include <bits/stdc++.h>
using namespace std;


int h[100], n, ans;

int solve() {
	cin >> n;
	
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cin >> h[i];
	}
	for (int i = 1; i < n-1; i++) {
		if (h[i] > h[i-1] && h[i] > h[i+1]) {
			cnt += 1;
		}
	}
	return cnt;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	
	for (int i = 1; i <= t; i++) {
		ans = solve();
		cout << "Case #" << i << ": " << ans << "\n";
	}
	return 0;
}

