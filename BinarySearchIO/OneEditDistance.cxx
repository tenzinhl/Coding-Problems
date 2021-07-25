#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	string s0, s1;
	cin >> s0 >> s1;
	long n, cnt = 0, s;
	bool ins = false;
	if (s0.length() != s1.length()) {
		ins = true;
		cnt += 1;
	}
	s = -1;
	if (s0.size() < s1.size()) {
		s = 0;
	} else if (s1.size() < s0.size()) {
		s = 1;
	}
	
	n = min(s0.length(), s1.size());
	int i = 0, j = 0;
	while (i < n and j < n) {
		if (s0[i] != s1[j]) {
			if (ins == true) {
				if (s == 0) {
					j++;
				} else {
					i++;
				}
				ins = false;
			} else {
				cnt += 1;
				i++, j++;
			}
		} else {
			i++, j++;
		}
	}
	
	if (cnt > 1) {
		cout << "false";
	} else {
		cout << "true";
	}
	return 0;
}

// DON'T FORGET TO INITIALIZE VARIABLES. I initialized almost nothing in my original solution
// and that led to a lot of errors.
