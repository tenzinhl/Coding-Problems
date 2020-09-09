#include <bits/stdc++.h>
using namespace std;


int main()
{
	long t;
	cin >> t;
	long long l, r;
	for (int i = 0; i < t; i++) {
		cin >> l >> r;
		if ((l + r) % 3 == 0 and 2 * l >= r and 2 * r >= l) {
			cout << "YES" << "\n";
		} else {
			cout << "NO" << "\n";
		}
	}
	return 0;
}

