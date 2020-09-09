#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9

const int LIM = (int) 1e5 + 8;
int n, val[LIM], sut[LIM];
unordered_map<int, int> sums;
string a;
void solve() {
	cin >> n;
	cin >> a;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		val[i] = a[i] - '0' - 1;
		sum += val[i];
		sums[sum] += 1;
		sut[i] = sum;
	}
	ll ans = 0;
	int x = 0, cur = 0;
	for (int i = 0; i < n; i++) {
		ans += sums[cur];
		x = val[i];
		cur += x;
		// cout << cur << " " << sums[x] << endl;
		sums[sut[i]] -= 1;
	}
	
	cout << ans << "\n";
	sums.clear();
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

/* 
1
5
11011
*/
