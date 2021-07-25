#include <bits/stdc++.h>
using namespace std;
#define ll long long

#define N 108
int n, s[N], e[N], l[N];
vector<int> stones;
// Comparison function returns bool (or int, 1 or 0 basically), and says whether or not first argument should be placed before second argument. (Easy enough to understand).
bool cmp(int x, int y) {
	int a = e[x] + e[y] - s[x] * l[y];
	int b = e[x] + e[y] - s[y] * l[x];
	return a > b;
}

long long dp[100][10008];
bool checked[100][10008];
long long getMax(int i, int time) {
	// cout << i << endl;
	if (checked[i][time]) {
		return dp[i][time];
	}
	int ind = stones[i];
	int ce = e[ind] - l[ind] * time;
	checked[i][time] = true;
	if (i == n - 1) {
		dp[i][time] = max(ce, 0);
		return dp[i][time];
	} else {
		ll a = getMax(i + 1, time);
		ll b;
		if (ce > 0) {
			b = getMax(i + 1, time + s[ind]) + ce;
		} else {
			b = 0;
		}
		dp[i][time] = max(a, b);
		return dp[i][time];
	}
}

// int dp[N * N];

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i] >> e[i] >> l[i];
		stones.push_back(i);
	}
	
	sort(stones.begin(), stones.end(), cmp);
	
	// for (int i = 0; i < n; i++) {
		// cout << stones[i] << "\n";
	// }
	// memset(dp, 0, sizeof(dp));
	
	ll ans = getMax(0, 0);
	stones.clear(); // FUCK, the reason it wasn't working was cause I forgot to reset the global vector... I really need to systematize these checks.
	memset(dp, 0, sizeof(dp));
	memset(checked, 0, sizeof(checked));
	cout << ans << "\n";
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

/* I just want to solidify what I learned from failing this problem the first time by writing it down
 *   First off, it's important to be highly wary of piecewise functions, take special note when they exist. 
 * 
 *   Secondly, when my intution doubts about the thoroughness of a solution, take the time to fully think it through (my doubts are usually
 * on point, 2.5: Don't go in on a half-way thought. Determine (ascertain even) what variable in your model IS the final answer, 
 * and find (or optimize) it with your program). 
 * 
 *   Thirdly, reiterating the first point, when considering rates, understand the program only has
 * an instantaneous understanding of the rate and doesn't know that it might change, so in from the
 * final reference of the solution it could be different. 
 * 
 *   Fourthly and finally, it is always useful to consider what rules bound a final solution, and use
 * those insights/rules to develop an algorithm that looks through those options. (In this case it was knowing to sort them,
 * in conjunction that taking the first stone isn't necessarily always optimal. I.E.: think backwards, AT LEAST ONCE
 * for ANY problem. (literally almost all problems I have come across, backwards thinking is beneficial).*/

/* YOU DID IT! YOU'RE AMAZING! YOU'RE THE BEST! I need to get better at dynamic programming lol.*/
