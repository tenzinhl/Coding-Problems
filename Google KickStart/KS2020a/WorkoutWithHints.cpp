#include <bits/stdc++.h>
using namespace std;

int t;

int solve() {
	int n, k;
	cin >> n >> k;
	
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	int d[n-1];
	for (int i = 0; i < n-1; i++) {
		d[i] = a[i+1] - a[i];
	}
	
	int lb, ub, mb;
	lb = 1;
	ub = a[n-1] - a[0];
	
	while (lb <= ub) {
		int k2 = 0;
		mb = (ub + lb) / 2;
		for (auto b : d) {
			k2 += ((b + mb - 1) / mb) - 1;
		}
		if (k2 > k) {
			lb = mb + 1;
		}
		else {
			ub = mb - 1;
		}
	}
	return lb;
}
			

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": ";
		cout << solve() << "\n";
	}
	return 0;
}

