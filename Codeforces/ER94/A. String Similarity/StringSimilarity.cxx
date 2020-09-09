#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9

int n;
string s;
void solve() {
	cin >> n;
	cin >> s;
	string ans;
	for (int i = 0; i < n; i++) {
		ans += s[2 * i];
	}
	cout << ans << "\n";
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

