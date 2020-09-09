#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	cin >> s;
	char prev = 0;
	int b = 0;
	int cb = 0;
	for (char cur : s) {
		if (cur == prev) {
			cb += 1;
		} else {
			b = max(cb, b);
			cb = 1;
		}
		prev = cur;
	}
	b = max(cb, b);
	
	cout << b;
	return 0;
}

