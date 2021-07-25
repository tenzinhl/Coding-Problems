#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9

void solve() {
	int n;
	cin >> n;
	vector<int> a;
	vector<int> b;
	bool odd[1008];
	memset(odd, 0, sizeof(odd));
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		if (abs(temp % 2) == 1) { // Solution, when checking for even/odd ONLY check
			// if temp % 2 == 0, since for odd numbers temp % 2 can be +- 1.
			a.push_back(temp);
			odd[i] = true;
		} else {
			b.push_back(temp);
		}
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end(), greater<int>());
	int aptr = 0;
	int bptr = 0;
	for (int i = 0; i < n; i++) {
		// cout << "odd[" << i << "]: " << odd[i] << "\n";
		if (odd[i]) {
			cout << a[aptr] << ' ';
			aptr++;
		} else {
			cout << b[bptr] << ' ';
			bptr++;
		}
	}
	cout << "\n";
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}

