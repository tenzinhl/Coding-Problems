#include <bits/stdc++.h>
using namespace std;


int solve() {
	int n, k;
	cin >> n >> k;
	int m[n];
	
	//populate array with cin
	for (int i = 0; i < n; i++) {
		cin >> m[i];
	}
	
	//create array that records differences between consecutive values
	//in array m
	int dif[n-1];
	for (int i = 0; i < n-1; i++) {
		dif[i] = m[i+1] - m[i];
	}
	
	int lb, ub, mb;
	lb = 1;
	ub = m[n-1] - m[0];
	
	while (lb <= ub) {
		int k2 = 0;
		mb = (ub + lb) / 2;
		for (auto c : dif) {
			k2 += ((c + mb - 1) / mb) - 1;
		}
		if (k2 > k) {
			lb = mb + 1;
		} else {
			ub = mb - 1;
		}
	}
	
	return lb;
} 
	

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	
	for (int i = 1; i <= t; i++) {
		int ans = solve();
		cout << "Case #" << i << ": " << ans << "\n";
	}
	return 0;
}

//final score. Not bad, only issue was k2 was not resetting to 0 for
//each loop of the binary search, YET THE CODE STILL PASSED 2 TEST CASES
//have no idea how that worked out. But whatever I guess lol. Time to go
//learn how to do the bundling problem.
