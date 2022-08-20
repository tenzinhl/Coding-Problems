#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9

int numDecodings(string s) {
		if (s[0] == '0') {
				return 0;
		}
		int twoMovesAgo = 1; // starts off before first letter
		int prevMove = 1; // starts off as first letter
		int curMove = 1;
		for (int i = 1; i < s.size(); i++) {
				if (s[i] == '0') {
						if ((s[i-1] == '0' or s[i-1] >= '3')) {
								return 0;
						}  
				}
				curMove = prevMove;
				if ((s[i - 1] == '1' and s[i] >= '1' and s[i] <= '9') or (s[i - 1] == '2' and s[i] >= '1' and s[i] <= '6')) {
						curMove += twoMovesAgo;
						if (i + 1 < s.size() and s[i+1] == '0') {
								curMove -= twoMovesAgo;
						}
				}
				twoMovesAgo = prevMove;
				prevMove = curMove;
		}
		return curMove;
}

int main()
{
	cout << numDecodings("22222");
	return 0;
}

