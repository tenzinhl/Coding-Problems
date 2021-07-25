#include <bits/stdc++.h>
using namespace std;
//parcels attempt two fresh start. Coming back to comp programming after
//attempting some web development stuff. omg web development sucks ass.

// July 16th: Just realized I never actually finished this one! wow.

int dist[250][250]; //error arose from naming array "distance", which is a STL function apparently lol
bool checked[250*250];
//dx[], dy[] consider implementing this later to not have to write out 4 queue.push statements
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
int r, c;
queue <int> q;

//LIT! after some roadblocks, it looks like our BFS function works!
void bfs() {
	while (!q.empty()) {
		int cur = q.front(); //coord is stored as i*250 + j
		q.pop();
		int x = cur % 250;
		int y = cur / 250;
		if (checked[cur] == true) //thought I could remove this line, but leads to infinite loop somehow? idk why
			continue;
		checked[cur] = true; //just ran this function and wondered why it was infinitely running, realized cuz I didn't add checked state lol.
		for (int i = 0; i < 4; i++) {
			int xp = x + dx[i];
			int yp = y + dy[i];
			if (xp >= 0 and xp < 250 and yp >= 0 and yp < 250 and checked[yp * 250 + xp] == false) { //only add square to queue if it's within 250x250 grid and unvisited
				q.push((yp * 250) + xp);
				dist[xp][yp] = dist[x][y] + 1;
			}
		}
	}
}
	
bool isPossible(int k) {
	int maxA = 0; //infinite loop error might be here, these bounds should be determined by r and c, not by problem constraints
	int minA = 500;
	int maxM = -250;
	int minM = 250;
	
	for (int i = 0; i < c; i++) {
		for (int j = 0; i < r; j++) { 
			if (dist[i][j] > k) {
				maxA = max((i+j), maxA);
				minA = min((i+j), minA);
				maxM = max((i-j), maxM);
				minM = min((i-j), minM);
			}
		}
	}
	
	for (int i = 0; i < c; i++) {
		for (int j = 0; i < r; j++) {
			int a = i + j; 
			int m = i - j;
			if (abs(a-maxA) <= k and abs(a-minA) <= k and abs(m-maxM) <= k and abs(m-minM) <= k)
				return true;
		}
	}
	
	return false;
}

void solve() {
	cin >> r >> c;
	string s;
	for (int j = 0; j < r; j++) { //oops, this should be j as the row number is the vertical axis
		cin >> s;
		for (int i = 0; i < c; i++) {
			if (s[i] == '1') {
				dist[i][j] = 0;
				q.push((j * 250) + i);
			}
		}
	}
	bfs();
	
	cout << dist[0][0];

	int lb, ub, mb;
	lb = 1;
	ub = 1;
	for (int i = 0; i < c; i++) { //quickly iterate through all elements of distance array to find max distance
		for (int j = 0; j < r; j++) {
			ub = max(dist[i][j], ub);
		}
	}
	
	cout << ub; //we are able to reach this point currently but runtime error somewhere in the binary search
	//wait I'm such a dumbass. lb has been uninitialized (and thus undefined could be some insane number) this whole time!
	while (lb <= ub) {
		mb = (lb + ub) / 2;
		if (isPossible(mb)) {
			lb = mb + 1;
		} else {
			ub = mb - 1;
		}
	}
	cout << ub << "\n";
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
//test case 
// 1
// 4 4
// 0000
// 0000
// 0010
// 0000
