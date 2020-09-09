#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Goal here is to start moving away from lengthy comments recording process,
// instead focusing on final product and important reminders. This is GridPaths attempt 2;

// This time around instead of making and updating a trie, I want to check if path matches
// target as we backtrack. Hopefully this is more efficient?

// FRIKK YEAH! THAT only took me 30-40 mins in a clean and smooth second try and it works great!
// I wonder why my other one is so much slower, I wonder if the checking the target string as you 
// backtrack is a necessary (and major) optimization. OK, so it looks like that was the case as I
// am exceeding the time limit in test cases where the string begins with a lot of ???'s. How can I
// optimize it more? Should I precompute the paths? lol. So next optimization is we can't make U's,
// where to fill the hole would be a must-be dead end. To be able to check this we add vector that stores
// move history. Should be very cheap to add.
#define N 7

bool board[N][N] = {true}; // initialize origin to checked
int dx[4] = {0, 0, -1, 1};  // D, U, L, R
int dy[4] = {1, -1, 0, 0};

unordered_map<char, int> ctoint = {
	{'D', 0},
	{'U', 1},
	{'L', 2},
	{'R', 3}
};

vector<int> path = {-1}; // give it a null start value so first check has something to access
string target; // global to be accessed by main and backtracking()
long step, cnt;

bool inBounds(int x, int y) {
	if (x >= 0 and x < N and y >= 0 and y < N) {
		return true;
	} else {
		return false;
	}
}

bool checkU(int x, int y) { // Returns true if (x, y) is unoccupied but also surrounded on 3 or more sides by walls
	if (!inBounds(x,y)) { // this got it working, let's go!
		return false;
	}
	if (board[x][y])
		return false;
	int xp, yp, c;
	c = 0;
	for (int i = 0; i < 4; i++) {
		xp = x + dx[i];
		yp = y + dy[i];
		if (xp < 0 or xp >= N or yp < 0 or yp >= N) {
			c += 1;
		} else if (board[xp][yp] == true) {
			c += 1;
		}
	}
	if (c >= 3) {
		return true;
	} else {
		return false;
	}
}

bool checkNode(int x, int y, int dir) {
	if (x >= N or x < 0 or y >= N or y < 0) {
		return false;
	}
	
	if (board[x][y]) {
		return false;
	}
	
	// Added optimization to run "split" check when running not just into wall but own path as well. Looks like it worked!
	if ((x == 0 or x == N - 1 or (board[x+dx[dir]][y])) and y > 0 and y < N - 1) {
		if (!board[x][y+1] and !board[x][y-1]) {
			return false;
		}
	}
	
	if ((y == 0 or y == N - 1 or (board[x][y+dy[dir]])) and x > 0 and x < N - 1) {
		if (!board[x-1][y] and !board[x+1][y]) {
			return false;
		}
	}
	
	// current step is step - 1, so previous is -2. This check is leading to -107 error code somehow. At time of check node path.push_back hasn't happened yet. Caused by out of bounds access on vector pretty sure.
	if (path.back() == dir) {
		int x2, y2;
		bool check1, check2;
		if (dir == 0 or dir == 1) { // if we moved up or down, check left and right
			y2 = y - dy[dir];
			check1 = checkU(x - 1, y2);
			check2 = checkU(x + 1, y2);
		} else {
			x2 = x - dx[dir];
			check1 = checkU(x2, y + 1);
			check2 = checkU(x2, y - 1);
		}
		if (check1 or check2) {
			return false;
		}
	}
	return true;
}

void updateBoard(int x, int y, int i) {
	
}
void backtracking(int x = 0, int y = 0) {
	step += 1;
	// cout << step << "\n";
	if (x == 0 and y == 6) {
		if (step == 49) {
			cnt += 1;
			// cout << "cnt increased \n";
		}
		step -= 1;
		return;
	}
	
	int xp, yp;
	
	if (target[step-1] != '?') {
		int i = ctoint[target[step-1]];
		xp = x + dx[i];
		yp = y + dy[i];
		if (checkNode(xp, yp, i)) {
			board[xp][yp] = true;
			path.push_back(i);
			backtracking(xp, yp);
			board[xp][yp] = false;
			path.pop_back();
		}
	} else {
		// Recursively check all adjacent nodes
		for (int i = 0; i < 4; i++) {
			xp = x + dx[i];
			yp = y + dy[i];
			if (checkNode(xp, yp, i)) {
				board[xp][yp] = true;
				path.push_back(i);
				backtracking(xp, yp);
				board[xp][yp] = false; // remember to unmark nodes when backtracking
				path.pop_back();
			}
		}
	}
	
	step -= 1;
	return;
}

int main()
{
	cin >> target;
	
	backtracking(0, 0);
	cout << cnt;
	return 0;
}

// WE DID IT! LETS GOOOOOOOOOOOOO!!!!!! YEAHHHHHHHHHH!!!! INTRODUCTORY PROBLEMSET COMPLETE!
