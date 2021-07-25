#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 1e9
#define LIM (int) 5e4 + 8

unordered_map<int, int> neighborl[LIM], neighborr[LIM]; // [row][col]
unordered_map<int, int> neighboru[LIM], neighbord[LIM]; // [col][row]


unordered_map<char, int> mp{
	{'N', 0},
	{'S', 1},
	{'E', 3},
	{'W', 2}
};


void solve() {
	int n, r, c, sr, sc;
	cin >> n >> r >> c >> sr >> sc;
	
	int i, x, y;
	x = sc;
	y = sr;
	neighborl[y][x] = x - 1;
	neighborr[y][x] = x + 1;
	neighboru[x][y] = y - 1;
	neighbord[x][y] = y + 1;
	
	string s; 
	cin >> s;
	for (char &a : s) {
		switch(a) {
			case 'N': 
				y -= 1;
				if (neighboru[x][y-1].count()) {
					int top = neighboru[x][y-1];
					int bottom = neighbord[x][y+1];
					neighbord[x][top] = bottom;
					neighboru[x][bottom] = top;
					neighboru[x].erase(y+1);
				}
				neighbord[x][y] = neighbord[x][y+1];
				neighbord[x].erase(y + 1);
		}
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
