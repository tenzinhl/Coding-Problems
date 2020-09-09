#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9

void solve() {
	string s;
	cin >> s;
	int x;
	cin >> x;
	string ans;
	ans.resize(s.size(), 'a');
	for (int i = 0; i < x and i + x < s.size(); i++) {
		ans[i + x] = s[i];
	}
	for (int i = s.size() - 1; i >= s.size() - x and i - x >= 0; i--) {
		if (ans[i - x] != 'a') {
			if (s[i] != ans[i - x]) {
				cout << -1 << "\n";
				return;
			}
		} else {
			ans[i - x] = s[i];
		}
	}
	for (int i = x; i < s.size() - x; i++) {
		if (s[i] == '0') {
			if (ans[i-x] == '1' or ans[i + x] == '1') {
				cout << -1 << "\n";
				return;
			}
			ans[i - x] = '0';
			ans[i + x] = '0';
		}
	}
	
	if (x > s.size()/2) {
		for (int i = s.size() - x - 1; i < x; i++) {
			if (s[i] == '1') {
				cout << -1 << "\n";
				return;
			}
		}
	}
	for (int i = 0; i < s.size(); i++) {
		if (ans[i] == 'a') {
			ans[i] = '1';
		}
	}
	for (int i = x; i < s.size() - x; i++) {
		if (s[i] == '1') {
			if (ans[i-x] != '1' and ans[i+x] != '1') {
				cout << -1 << "\n";
				return;
			}
		}
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

/* The fringe case I was forgetting was that some characters might not have either
 * a i - x or a i + x that exists, in which case it defaults to 0. Had to reverse engineer
 * that.*/
