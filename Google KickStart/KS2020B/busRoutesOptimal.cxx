#include <bits/stdc++.h>
using namespace std;

long long n, d;
long long x[1001];

void solve() {
	cin >> n >> d;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	
	long long cd;
	cd = d;
	for (int i = n - 1; i >=0 ; i--) { //LOL I had i++ instead of i-- here. Surprised there's no compiler thing to catch that.
		cd = (cd / x[i]) * x[i];
	}
	
	cout << cd;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": ";
		solve();
		cout << "\n";
	}
	return 0;
}
