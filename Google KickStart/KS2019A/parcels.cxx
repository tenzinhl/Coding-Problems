#include <bits/stdc++.h>
using namespace std;

int r, c;
string oi[250];
//row and column of node will be inherent to parent array. i.e.: the node
//stored in nodes[i][j] will be in column i row j.

struct node {
	int x, y;
	int dist = 0;
	bool cd = false;
}

node grid[250][250];
queue <node> q;

void bfs() {
	while (q.empty() == false) {
		node cur = q.front();
		q.pop();
		int col = cur.x;
		int row = cur.y;
		if (cur.cd == true || x < 0 || x >= c || y < 0 || y >= r) continue;
		cur.cd = true;
		q.push(grid[i-1][j]);
		q.push(grid[i+1][j]);
		q.push(grid[i][j-1]);
		q.push(grid[i][j+1]);
		grid[i-1][j].dist = cur.dist + 1;
		grid[i+1][j].dist = cur.dist + 1;
		grid[i][j-1].dist = cur.dist + 1;
		grid[i][j+1].dist = cur.dist + 1;
	}
}

void solve() {
	cin >> r >> c;
	for (int j = 0; j < r; j++) {
		cin >> oi[j];
		for (int i = 0; i < c; i++) {
			grid[i][j].x = i;
			grid[i][j].y = j;
			if (oi[j][i] == 1) {
				grid[i][j].dist = 0;
				q.push(grid[i][j]);
			}
		}
	}
	
	bfs();
	int kmax = 0;
	for (auto col : grid) {
		for (auto sq : grid) {
			kmax = max(kmax, sq.dist);
		}
	}
	
	int lb, ub, mb;
	lb = 0;
	ub = kmax;
	node toCheck[62500];
	m = 0;
	while (lb <= ub) {
		int k = (ub + lb) / 2;
		for (auto col : grid) {
			for (auto sq : grid) {
				if (sq.dist > k) toCheck[m++] = sq;
			}
		}
		
		char inRange[250][250];
		for (node c : toCheck) {
			for (int i = 0; i < 250; i++) {
				for (int j = 0; j < 250; j++) {
					if
	}
	

}

int main()
{
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}

