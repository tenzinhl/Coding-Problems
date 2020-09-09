#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, m;

int an[1000], am[1000];

void solve() {
	cin >> n;
	cin >> m;
	
	for (int i = 0; i < n; i++) {
		cin >> an[i];
	}
	
	for (int i = 0; i < m; i++) {
		cin >> am[i];
	}
	
	sort(an, an + n);
	sort(am, am + m);
	
	int in = 0, im = 0;
	while (in < n and im < m) {
		if (an[in] == am[im]) {
			cout << "YES \n1 " <<  an[in] << "\n";
			return;
		} else if (an[in] < am[im]) {
			in += 1;
		} else if (an[in] > am[im]) {
			im += 1;
		}
	}
	
	cout << "NO \n";
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

