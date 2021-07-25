#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 1e9
#define LIM (int) 5e4 + 8

// int rows[LIM][2], cols[LIM][2];
// have array that stores leftmost/rightmost or topmost/bottomost unexplored square for given row or column
unordered_map<int, int> xneighbor[LIM]; // [row][col]
unordered_map<int, int> yneighbor[LIM]; // [col][row]

unordered_map<char, int> mp{
	{'N', 0},
	{'S', 1},
	{'E', 3},
	{'W', 2}
};

int dx[2] = {-1, 1};
int dy[2] = {-1, 1};

void solve() {
	int n, r, c, sr, sc;
	cin >> n >> r >> c >> sr >> sc;
	
	for (int i = 0; i < LIM; i++) {
		rows[i][0] = INF;
		cols[i][0] = INF;
		rows[i][1] = -1;
		cols[i][1] = -1;
	}
	
	// memset(rows, -1, sizeof(rows));
	// memset(cols, -1, sizeof(cols));
	// (0, 0) will be topleft corner. Rows are y, cols are x
	string s;
	cin >> s;
	
	int i, x, y;
	x = sc;
	y = sr;
	
	rows[sr][0] = sc - 1;
	rows[sr][1] = sc + 1;
	cols[sc][0] = sr - 1;
	cols[sc][1] = sr + 1;
	
	for (auto &a : s) { // cool new pass by reference we learned yesterday
		i = mp[a];
		if (i >= 0 and i < 2) {
			y = cols[x][i];
			cols[x][i] = y + dy[i];
			rows[y][0] = min(rows[y][0], x - 1);
			rows[y][1] = max(rows[y][1], x + 1);
		} else {
			i %= 2;
			x = rows[y][i];
			rows[y][i] = x + dx[i];
			cols[x][0] = min(cols[x][0], y - 1);
			cols[x][1] = max(cols[x][1], y + 1);
		}
		cout << x << ' ' << y << endl;
		// cout << "cols[2][1]: " << cols[2][1] << endl;
	}
	
	cout << y << ' ' << x << "\n";
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

// Aww man, nice try, but I forgot that there could be "holes", where an unexplored
// square, or multiple for that matter, are surrounded by explored squares, in which
/* case my basic segment approach will be wrong. OOH, I was close though (reading the
 * editorial rn, and you do use segments (perhaps duh), but the idea is to use multiple
 * segments and keep track of them.*/
