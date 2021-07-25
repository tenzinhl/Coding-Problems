#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9

bool visited[7][7]; // row, pos
stack<pair<int,int>> patha, pathb;
int s;
int getScore(bool turnA, bool board[][], int rowA, int posA, int rowB, int posB, int score) {
	if (turnA) {
		curRow = rowA;
		curPos = posA;
	} else {
		curRow = rowB;
		curPos = posB;
	}
	int ans = -1000;
	// curPos % 2 returns true if curPos is odd
	if (curPos % 2 and curRow < s and !board[curRow + 1][curPos + 1]) {
		board[curRow + 1][curPos + 1] = true;
		if (turnA) {
			ans = max(ans, getScore(!turnA, board, curRow + 1, curPos + 1, rowB, posB);
		} else {
			ans = max(ans, getScore(!turnA, board, rowA, posB, curRow + 1, curPos + 1);
		}
		board[curRow + 1][curPos + 1] = false;
	}
	if (curPos % 2 == 0 and curRow > 1 and !board[curRow - 1][curPos - 1]) {
		board[curRow - 1][curPos - 1] = true;
		if (turnA) {
			ans = max(ans, getScore(!turnA, board, curRow - 1, curPos - 1, rowB, posB);
		} else {
			ans = max(ans, getScore(!turnA, board, rowA, posB, curRow - 1, curPos - 1);
		}
		board[curRow - 1][curPos - 1] = false;
	}
	if (curPos > 1 and !board[curRow][curPos - 1]) {
		board[curRow][curPos - 1] = true;
		if (turnA) {
			ans = max(ans, getScore(!turnA, board, rowA, posA - 1, rowB, posB));
		} else { 
			ans = max(ans, getScore(!turnA, board, rowA, posA, rowB, posB - 1));
		}
	}
}
void solve() {
	int ra, pa, rb, pb, c;
	cin >> s >> ra >> pa >> rb >> pb >> c;
	patha.push(make_pair(ra,pa));
	pathb.push(make_pair(rb,pb));
	int curRowA, curPosA, curRowB, curPosB;
	while (!patha.empty() or !pathb.empty()) {
		if (!patha.empty()) {
			curRowA = patha.top().first;
			curPosA = patha.top().second;
			patha.pop();
			if (curPosA % 2 == 0) {
				if (curPosA - 1 >= 1 and curRowA >= 2 and !visited[curRowA - 1][curPosA - 1]) {
					patha.push(make_pair(curRowA
				}
			}
		}
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

/* Reading analysis after competition is over. Transferring notes from
 * paper to here:
 * AGH. So as I thought, simple simulation would have been good enough
 * for this problem as most branches end far earlier than max depth. Would've
 * made sense to do it recursively in htis case since depth would have
 * been so low. Well we can implement it later.
 * 
 * Takeaway: At one point I wanted to implement the simulation (as you can
 * see from the stacks) but I'm too slow when it comes to implementing backtracking...
 * So that's something to work on for sure.
 * 
 * (The next day): Wait a second... I think implementing DFS iteratively is pretty
 * much pointless! You might have some memory savings, but it would only be by
 * a constant factor! Goddamn it. Since in dfs all the information you need to
 * pass recursively you would need to add to each frame in the iterative stack
 * anyways! The overhead of the memory the function frame uses is the only thing
 * that differs! Backtracking is another example of where recursion should be
 * used! (Since it's basically dfs).
 * 
 * In fact, recursion may be superior since we only need to store one board state.
 * (Because at the end of each recursion level we can "undo" a move by setting
 * a position false.) However with the iterative stack, I think there is no other
 * way but to store a board state in each stack frame. */
