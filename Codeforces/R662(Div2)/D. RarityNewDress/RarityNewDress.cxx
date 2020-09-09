#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 2008;
int board[N][N];
int dp[N][N]; // max size of rhombus centered on this square

visited[N][N];
vector<pair<int, int>> q1;
vector<pair<int, int>> q2;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int rows, cols;
bool inbounds(int x, int y) {
	if (x >= 0 and x < cols and y >= 0 and y < rows) {
		return true;
	}
	return false;
}
void bfs(int x, y) {
	int tar = board[x][y];
	visited[x][y] = true;
	pair<int, int> npos = make_pair(x, y);
	for (int i = 0; i < 4; i++) {
		npos.first = x + dx[i];
		npos.second = y + dy[i];
		q1.push_back(npos);
	}
	
	int xp, yp;
	int x2, y2;
	int sz = 1;
	bool check = true;
	while (check) {
		for (auto &pos : q1) {
			xp = pos.first;
			yp = pos.second;
			if (board[xp][yp] != tar) {
				check = false;
				break;
			}
			for (int i = 0; i < 4; i++) {
				x2 = xp + dx[i];
				y2 = yp + dy[i];
				if (inbounds(x2,y2) and !visited[x2][y2]) {
					q2.push_back(make_pair(x2, y2));
					visited[x2][y2] = true;
				}
			}
		}
		if (check) sz += 1;
		q1.clear();
		swap(q1, q2);
	}
	dp[x][y] = size;
	memset(visited, 0, sizeof(visited));
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> rows >> cols;
	for (int j = 0; j < rows; j++) {
		dp[0][j] = 1;
		for (int i = 0; i < cols; i++) {
			cin >> board[i][j];
			board[i][j] -= 'a';
		}
	}
	
	for (int i = 0; i < cols; i++) {
		dp[i][0] = 1;
	}
	
	// each solo square can adds to the sum.
	ll sum;
	
	
	return 0;
}

/* Hold up, I must have been high while thinking of this solution. BFS off of each square in the grid
 * is proportional to O(N^4), which is waaaay too much. What was I thinking lol. There has to be a way to
 * do this better dynamically? Maybe optimizng the bfs to utilize previous results is good enough? idk. Def
 * have to think about this.
 * 
 * I think in all of my tiredness I confused my time complexity analysis for this problem with that for the Kickstart
 * problem I'm also working on. (200 is one 0 away from 2000, but for n^4 that makes a huge difference, and the other problem
 * is only n^3).*/
