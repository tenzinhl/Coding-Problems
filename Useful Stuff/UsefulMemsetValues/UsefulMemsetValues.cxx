#include <bits/stdc++.h>
using namespace std;

void solve() {
	
}

// Useful memset numbers to know. 128 will cause most significant digit to become 1, and int to be negative. With memset
// largest positive int you can get is with 127. In the solution to running on fumes ch2 the guy uses 60, which gives a 
// value of a little over 1.01 * 10^9 (with 127 you get over 2*10^9), and with long long (8 bytes wide) memset(60) gives over 4 * 10^18 (127 gives
// over 9 * 10^18). Good sort of thing to know. -1 also works as -1 is indicated by all ones in signed 2's complement, and thus memset -1, will
// actually store -1.
int a[50];
int main() {
	memset(a, 60, sizeof(a));
	cout << a[35] << endl;
	
	memset(a, -1, sizeof(a));
	cout << a[35] << endl;
}

/* Value table (Will translate to AT LEAST given value);
 * Ints (4-byte wide):
 * "60" => 1 * 10^9
 * "127" => 2 * 10^9
 * 
 * Long long (8-bytes wide):
 * "60" => 4 * 10^18
 * "127" => 9 * 10^18
 *  */
