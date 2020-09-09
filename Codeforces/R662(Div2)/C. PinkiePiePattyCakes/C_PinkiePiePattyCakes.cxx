#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define LIM (int) 1e5 + 8

int cnt[LIM];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		memset(cnt, 0, sizeof(cnt));
		int n; 
		cin >> n;
		int a, mf = 0; // mf is max frequency
		int f = 0; // number of types that have max frequency.
		for (int j = 0; j < n; j++) {
			cin >> a;
			cnt[a] += 1;
			if (cnt[a] > mf) {
				mf = cnt[a];
				f = 1;
			} else if (cnt[a] == mf) {
				f += 1;
			}
		}
		int ans = (n - f)/(mf - 1) - 1;
		cout << ans << "\n";
	}
	return 0;
}

