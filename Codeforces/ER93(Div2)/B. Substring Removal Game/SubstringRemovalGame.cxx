#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9

string s;
int chains[100];
void solve() {
	cin >> s;
	int curindex = 0;
	for (auto &c : s) {
		if (c == '1') {
			chains[curindex] += 1;
		} else {
			curindex += 1;
		}
	}
	sort (chains, chains + s.length(), greater<int>());
	
	int ans = 0;
	for (int i = 0; chains[i] > 0; i += 2) {
		ans += chains[i];
	}
	cout << ans << "\n";
	memset(chains, 0, sizeof(chains));
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

