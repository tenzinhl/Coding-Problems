#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9

bool checkCharCount(int charCount[]) {
	int cnt = 0;
	int i = 0;
	bool firstFound = false;
	while (!firstFound) {
		if (charCount[i] > 0) {
			cnt = charCount[i];
			firstFound = true;
		}
		i++;
	}
	while (i < 26) {
		if (charCount[i] != 0 and charCount[i] != cnt) {
			return false;
		}
		i++;
	}
	return true;
}

void printCharCount(int charCount[]) {
	for (int i = 0; i < 26; i++) {
		if (charCount[i] > 0) {
			cout << charCount [i] << " ";
		}
	}
	cout << endl;
}

string isValid(string s) {
	int charCount[26];
	memset(charCount, 0, sizeof(charCount));
	for (int i = 0; i < s.size(); i++) {
		charCount[s[i] - 'a'] += 1;
	}
	
	bool possible = false;
	possible = checkCharCount(charCount);
	int i = 0;
	while (!possible and i < 26) {
		// cout << i << endl;
		charCount[i] -= 1;
		possible = checkCharCount(charCount);
		charCount[i] += 1;
		i++;
	}
	
	if (possible) {
		return "YES";
	}
	return "NO";
}

int main()
{
	cout << isValid("abcdefghhgfedecba") << endl;
	return 0;
}

// e is at index 4.
/* SO MANY DUMB MISTAKES TODAY. I wasn't setting possible equal to the return
 * value of checkCharCount so it didn't even matter if it returned true. GOD.*/
