#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define LIM 308

int dp[LIM][LIM]; // stores longest width of which this is rightmost point
int v[LIM][LIM];
void solve() {
	int r, c, k;
	cin >> r >> c >> k;
	
	for (int j = 0; j < r; j++) {
		for (int i = 0; i < c; i++) {
			cin >> v[i][j];
		}
	}
	
	// WOOPS, missed that the prompt says thickness difference is between entire row, not just adjacent...
	// Although... because LIMs are so low, we can probably just naively check all to find max width for dp[i][j]
	// anyways lol.
	
	// populates dp array with max length of valid row of which [i][j] is the rightmost point
	int ip = 0, lb = 0, ub = 0, cnt;
	for (int j = 0; j < r; j++) {
		dp[0][j] = 1;
		for (int i = 1; i < c; i++) {
			ip = i;
			lb = v[i][j];
			ub = v[i][j];
			cnt = 1;
			while (ip > 0) {
				ip--;
				if (v[ip][j] < ub)
					lb = min(v[ip][j], lb);
				if (v[ip][j] > lb)
					ub = max(v[ip][j], ub);
				if (abs(ub - lb) > k)
					break;
				cnt += 1;
			}
			dp[i][j] = cnt;
		}
	}
	
	// Aug. 8: coming back to this problem I was slightly worried about the time complexity for finding the max,
	// since I couldn't think of a method that allowed you to find the max possible area for a given column without
	// iterating through the column more than once. Thankfully, I remembered LIM = 300, and with O(N^3) we should still be fine
	// and can just naively check every possible width for a given row.
	
	// Checks each column for the maximum possible area it can form in which
	int z, w;
	int ma = 0; // max area
	for (int i = 0; i < c; i++) {
		for (int m = i + 1; m > 0; m--) {
			z = 0;
			w = 0;
			for (int j = 0; j < r; j++) {
				if (dp[i][j] >= m) {
					z += 1;
					w = max(w, z);
				} else {
					z = 0;
				}
			}
			ma = max(ma, m * w);
		}
	}
	cout << ma << "\n";
	memset(dp, 0, sizeof(dp));
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}

// I think this is a good example of a non-DP problem (even though I named an array dp).
// According to Wikipedia, merge-sort is based on combining optimal solutions to subproblems,
// but they are non-overlapping, and thus it is not dp. That makes sense! You combine two sorted
// subarrays, but it isn't dp as the sorting of one is not affected or based on the sorting of the other.

// WOW, that went really smoothly. Nice job, EZ Clap. I'm getting better at this, which is nice.
