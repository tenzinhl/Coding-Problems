#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 1e9
#define LIM (int) 5e4 + 8

unordered_map<int, pair<int, int>> ny[LIM];// maps coordinate to a pair. first is left/up, second is right/bottom neighbor.
unordered_map<int, pair<int, int>> nx[LIM]; 

unordered_map<char, int> mp{
	{'N', 0},
	{'S', 1},
	{'W', 2},
	{'E', 3}
};

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void solve() {
	int n, r, c, sr, sc;
	cin >> n >> r >> c >> sr >> sc;
	
	string s;
	cin >> s;
	
	ny[sc][sr] = make_pair(sr - 1, sr + 1);
	nx[sc][sr] = make_pair(sc - 1, sc + 1);
	
	int x, y, xp = 0, yp = 0;
	x = sc;
	y = sr;
	
	int ln, rn, un, dn; // store left, right, up, down, neighbors.
	for (auto &dir : s) {
		int i = mp[dir];
		xp = x + dx[i];
		yp = y + dy[i];
		// cout << "pre: " << yp << ' ' << xp << endl; // Diagnostic line
		// So I forgot to actually add the sliding movement, i.e.: save it in xp and yp... this also complicates merging. nvm, I was thinking wrong
		if (dx[i] == -1 and nx[xp].count(yp))
			xp = nx[xp][yp].first;
		if (dx[i] == 1 and nx[xp].count(yp))
			xp = nx[xp][yp].second;
		if (ny[xp].count(yp)) {
			if (dy[i] == -1)
				yp = ny[xp][yp].first;
			if (dy[i] == 1)
				yp = ny[xp][yp].second;
		}
		
		ln = xp - 1;
		rn = xp + 1;
		dn = yp + 1;
		un = yp - 1;
		
		if (ny[xp].count(yp - 1))
			un = ny[xp][yp - 1].first;
		if (ny[xp].count(yp + 1))
			dn = ny[xp][yp + 1].second;
		if (nx[xp - 1].count(yp))
			ln = nx[xp - 1][yp].first;
		if (nx[xp + 1].count(yp))
			rn = nx[xp + 1][yp].second;
		// merge down here, since dependent on each other orderwise
		// Neighbor arrays [col][row] start on a visited (col, row), and then point to nearest unexplored square in given direction.
		// n, s, w, e
		if (ny[xp].count(yp - 1))
			ny[xp][un + 1].second = dn;
		if (ny[xp].count(yp + 1))
			ny[xp][dn - 1].first = un;
		if (nx[xp - 1].count(yp))
			nx[ln + 1][yp].second = rn;
		if (nx[xp + 1].count(yp))
			nx[rn - 1][yp].first = ln;
		
		// if (dir == 0 and ny[xp].count(yp)) {
			// yp = ny[xp][yp].first;
		// }
		// if (dir == 1 and ny[xp].count(yp)) {
			// yp = ny[xp][yp].second;
		// }
		// if (dir == 2 and nx[xp].count(yp)) {
			// xp = ny[xp][yp].first;
		// }
		// if (dir == 3 and nx[xp].count(yp)) {
			// xp = ny[xp][yp].second;
		// }
		
		// if (!nx[xp - 1].count(yp)) {
			// ln = xp - 1;
		// } else {
			// ln = nx[xp - 1][yp].first;
		// }
		// if (!nx[xp + 1].count(yp)) {
			// rn = xp + 1;
		// } else {
			// rn = nx[xp + 1][yp].second;
		// }
		
		// nx[xp][yp] = make_pair(ln, rn);
		
		// if (ny[xp].count(yp - 1)) {
			// un = ny[xp][yp - 1].first;
		// } else {
			// un = yp - 1;
		// }
		
		// if (ny[xp].count(yp + 1)) {
			// dn = ny[xp][yp + 1].second;
		// } else {
			// dn = yp + 1;
		// }
		
		// ny[xp][yp] = make_pair(un, dn);
		// cout << yp << ' ' << xp << "\n"; // Diagnostic line
		nx[xp][yp] = make_pair(ln, rn);
		ny[xp][yp] = make_pair(un, dn);
		x = xp;
		y = yp; // omg, can't believe I forgot this.
	}
	
	cout << yp << ' ' << xp << "\n";
	
	for (int i = 0; i < LIM; i++) {
		nx[i].clear();
		ny[i].clear();
	}
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

// origin in this problem is (1,1), (topleftmost square).
/* ANOTHER TEACHABLE MOMENT: So I kept stopping myself and trying other solutions,
 * second guessing etc., because I was worried about space complexity. I kept thinking
 * about Rows * columns when it was more important to see that the number of map items
 * I would need is the number of outer squares touching the path, and that the maximum
 * is only directly proportional total path length (in worst case). And since path length
 * is only 5e4 we are EASILY within space complexity limits.
 * 
 * SO the tl;dr: When thinking about space complexity, carefully consider what actually matters!
 * 
 * also, I discourage myself too easily. Work through an idea you have, even if worried it will be
 * too slow or take too much memory (as long as it's optimal strategy), as this can help develop
 * final solution, and helps with thinking overall.
 * 
 * tltl;drdr: Complete initial idea if certain it provides optimal answer. DONT WORRY ABOUT SPACE
 * COMPLEXITY OR TIME COMPLEXITY TOO MUCH.*/
 
 // WE'RE INSANE, WE GOT IT THROUGH, Pog Actually Though. Really good job on this one.
