#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Program to understand how map "[]" operator handles a key that doesn't exist
// in the map yet. So it creates a new element in the map with the element's default
// constructor. Thankfully for us, the default constructor on int returns a value of 0,
// so we can use this in our Facebook Timber solution.
unordered_map<int, int> mp;

int main()
{
	// cout << mp[4];
	// mp[5] = 1;
	// long a[500];
	// cout << a[50] << ' ' << mp[20] << ' ' << mp[3000];
	
	for (int i = 0; i < 8000000; i++) {
		if (mp[i] != 0) {
			cout << "Not 0\n";
		}
	} // Well from this test I can say Nlog(N) starts to get dicey once you hit the millions.
	return 0;
}

