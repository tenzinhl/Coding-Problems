#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
void solve() {
	cin >> n;
	cout << (n / 2) + 1 << "\n";
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

