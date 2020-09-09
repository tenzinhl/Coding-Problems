#include <bits/stdc++.h>
using namespace std;

//also holy crap this was so much easier than the previous two problems wtf
int main()
{
	long long n;
	cin >> n;
	long long ans = 1;
	for (int i = 0; i < n; i++) {
		ans = (2 * ans) % (1'000'000'000 + 7);
	}
	//2^n % (1e9 + 7)
	
	cout << ans; //LOL I forgot to cout in my first submission
	return 0;
}

