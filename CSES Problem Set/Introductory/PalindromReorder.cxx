#include <bits/stdc++.h>
using namespace std;
//seems like a deque problem
//account for fact that you can have one letter that there is only one of
//in the palindrome (if it's in the middle).

deque <char> p;
long cnt[26];
int oddcnt, oddi;
int main()
{
	string s;
	cin >> s;
	for (auto c : s) {
		cnt[c - 'A'] += 1;
	}
	for (int i = 0; i < 26; i++) {
	//you can have one letter that has an odd count. fix this
		if (cnt[i] % 2 != 0) {
			oddcnt += 1;
			oddi = i;
		}
	}
	
	if (oddcnt > 1) {
		cout << "NO SOLUTION";
		return 0;
	} else if (oddcnt == 1) {
		while (cnt[oddi] > 0) {
			p.push_front('A' + oddi);
			cnt[oddi] -= 1;
		}
	}
	
	//online it says non-zero value is interpreted as true, but considering 
	//this line only works if you use > 0 and not == true, I'm not sure about that.
	
	for (int i = 0; i < 26; i++) {
		while (cnt[i] > 0) { 
			cnt[i] -= 2;
			p.push_front('A' + i);
			p.push_back('A' + i);
		}
	}
	
	while (p.empty() != true) {
		cout << p.front();
		p.pop_front();
	}
	
	return 0;
}

