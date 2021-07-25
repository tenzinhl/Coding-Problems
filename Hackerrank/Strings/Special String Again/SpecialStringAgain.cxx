#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9

int longestChain[(int) 1e6 + 8]; // stores length of chain of same characters ending at this point.
int lengthofPalindrome[(int) 1e6 + 8]; // Stores length of palindrome with one different character at the center.
// Define length of palindrome as number of elements starting at center character ending at right most. So min
// length of 2.
long substrCount(int n, string s) {
	long long ans = 1;
	longestChain[0] = 1;
	lengthofPalindrome[0] = 0;
	for (int i = 1; i < n; i++) {
		if (s[i-1] == s[i]) {
			ans += longestChain[i-1] + 1;
			longestChain[i] = longestChain[i-1] + 1;
			if (lengthofPalindrome[i-1] > 0 and i - 2 * lengthofPalindrome[i-1] >= 0) {
				if (s[i - 2 * lengthofPalindrome[i-1]] == s[i]) {
					lengthofPalindrome[i] = lengthofPalindrome[i-1] + 1;
					ans += 1;
				} else {
					lengthofPalindrome[i] = 0;
				}
			} 
		} else {
			ans += 1;
			longestChain[i] = 1;
			if (s[i-2] == s[i]) {
				lengthofPalindrome[i] = 2;
				ans += 1;
			} else {
				lengthofPalindrome[i] = 0;
			}
		}
	}
	return ans;
}

int main()
{
	return 0;
}

/* Somehow I passed all sample test cases on first go hahha. I was so surprised.
 * Then I failed 14/17 of the test cases LOL.
 * 
 * GREAT JOB. We did it. I was just off by one index, I had done my index math wrong.
 * Found the error pretty quickly though thankfully. Wasn't supposed to add one to index when
 * checking for palindrome with single different character.*/

