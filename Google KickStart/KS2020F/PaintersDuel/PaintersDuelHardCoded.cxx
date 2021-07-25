#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9

void solve() {
	int s, ra, pa, rb, pb, c;
	cin >> s >> ra >> pa >> rb >> pb >> c;
	int ri, pi;
	for (int i = 0; i < c; i++) {
		cin >> ri >> pi;
	}
	if (c == 2) {
		cout << 0 << "\n";
		return;
	}
	if (c == 1) {
		if (ri == 2 and pi == 2) {
			cout << 0 << "\n";
			return;
		}
		if (rb == 2 and pb == 2) {
			cout << -1 << "\n";
		} else {
			cout << 1 << "\n";
		}
		return;
	}
	if (rb == 2 and pb == 2) {
		cout << -1 << "\n";
	} else if (ra == 2 and pa == 2){
		cout << 1 << "\n";
	} else {
		cout << 2 << "\n";
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
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}

