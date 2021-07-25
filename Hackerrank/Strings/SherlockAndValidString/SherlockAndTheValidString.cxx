#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9

string isValid(string s) {
	int charCount[26];
	memset(charCount, 0, sizeof(charCount));
	for (int i = 0; i < s.size(); i++) {
		charCount[s[i] - 'a'] += 1;
	}
	int cnt;
	bool first = false;
	int deletionDistance = 0;
	int i = 0;
	while (!first) {
		if (charCount[i] > 0) {
			first = true;
			cnt = charCount[i];
		}
		i++;
	}
	
	while (i < 26) {
		if (charCount[i] > 0) {
			deletionDistance += abs(cnt - charCount[i]);
		}
		i++;
	}
	
	if (deletionDistance <= 1) {
		return "YES";
	}
	return "NO";
}

int main()
{
	return 0;
}

