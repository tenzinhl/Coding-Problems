#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	if (n <= 3) {
		if (n == 1) {
			cout << n;
			return 0;
		}
		cout << "NO SOLUTION";
		return 0;
	}
	
	if (n == 4) {
		cout << "2 4 1 3";
		return 0;
	}
	
	int l = n/2;
	int u = n;
	while (u > n / 2) {
		cout << u << " ";
		if (l > 0) {
			cout << l << " ";
		}
		u--, l--;
	}
	
	return 0;
}

