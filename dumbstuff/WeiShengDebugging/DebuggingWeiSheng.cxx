#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9

string isValid(string s) {
	map<char, int> m;
	for (int i = 0; i < s.size(); i++) {
		if (m.count(s[i]) > 0) {
			// m.insert(pair<char, int>(s[i],m[s[i]] + 1));
			*m.find(s[i]) = *m.find(s[i]) + 1;
		} else {
			m.insert(pair<char, int>(s[i],1));
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	return 0;
}

