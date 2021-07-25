#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9

string twoStrings(string s1, string s2) {
	unordered_set<char> st;
	for (int i = 0; i < s1.size(); i++) {
		st.insert(s1[i]);
	}
	for (int i = 0; i < s2.size(); i++) {
		if (st.count(s2[i])) {
			return "YES";
		}
	}
	return "NO";
}

int main()
{
	return 0;
}

