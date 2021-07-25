#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9

int alternatingCharacters(string s) {
	int ans = 0;
	char prev = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == prev) {
			ans += 1;
		}
		prev = s[i];
	}
	return ans;
}

int main()
{
	return 0;
}

