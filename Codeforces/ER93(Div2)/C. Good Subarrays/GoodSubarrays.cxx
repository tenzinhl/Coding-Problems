#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9

const int LIM = (int) 1e5 + 8;
int tree[LIM << 2], tsize;
int n;

void update(int ind) {
	while (ind > 1) {
		ind >>= 1;
		tree[ind] = tree[ind * 2] + tree[ind * 2 + 1];
	}
	return;
}

void solve() {
	cin >> n;
	tsize = 1;
	while (tsize < n) {
		tsize <<= 1;
	}
	
	for (int i = 0; i < n; i++) {
		cin >> tree[tsize + i]
		update(tsize + i);
	}
	
	for (int i = 0; i < tsize + n; i++) {
		
	}
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

