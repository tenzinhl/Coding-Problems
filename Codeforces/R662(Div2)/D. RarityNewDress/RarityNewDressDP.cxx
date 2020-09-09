#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define LIM 2008

int rows, cols;
int board[LIM][LIM];
int dp[LIM][LIM];

int getSize(int i, int j) {
	int val = board[i][j];
	if (board[i][j-2] != val or board[i-1][j-1] != val or board[i][j-1] != val 
		or board[i+1][j-1] != val) {
		return 1;
	}
	return min(dp[i][j-2], min(dp[i-1][j-1], dp[i+1][j-1])) + 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> rows >> cols;
	
	if (rows <= 2) {
		cout << rows * cols << endl;
		return 0;
	}
	
	string s;
	for (int j = 0; j < rows; j++) {
		cin >> s;
		for (int i = 0; i < cols; i++) {
			board[i][j] = s[i];
			board[i][j] -= 'a';
		}
	}
	
	// Fill top two rows with size of 1.
	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < 2; j++) {
			dp[i][j] = 1;
		}
	}
	
	// populate border (since easily known, and to prevent OOB array access).
	for (int j = 0; j < rows; j++) {
		dp[0][j] = 1;
		dp[cols-1][j] = 1;
	}
	
	for (int j = 2; j < rows; j++) {
		for (int i = 1; i < cols - 1; i++) {
			dp[i][j] = getSize(i, j);
		}
	}
	
	// iterate through dp array and add total ways to make rhombus
	long long ans = 0;
	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) {
			ans += dp[i][j];
		}
	}
	
	cout << ans << endl;
	return 0;
}

/* So I'm thinking: if we wanna do this dynamically, we store the maximum size of a rhombus of
 * which [i][j] is the bottom-most square, and like the largest square problem, we are bounded by
 * the size of 3 nearby squares (plus 1 extra check). In this way it's constant time per check, for
 * O(N * M) overall. */
// Good stuff! It got accepted.
