#include <bits/stdc++.h>
using namespace std;
#define ll long long

long n, a[100000], cnt; // I do not believe number of stones in a pile matters
void solve() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> a[i];
	}
	cin >> a[n - 1];
	
	// I was oversimplifying the game. Let's just play it with a backwards for-loop
	bool first = true;
	for (int i = n - 2; i >= 0; i--) {
		if (first == true) {
			if (a[i] > 1) {
				first = true;
			} else {
				first = false;
			}
		} else if (first == false) {
			first = true;
		}
	}
	
	if (first == true) {
		cout << "First \n";
	} else {
		cout << "Second \n";
	}
	
	// if (oddcnt % 2 == 0) {
		// cout << "First \n";
	// } else {
		// cout << "Second \n";
	// }
	
	// oddcnt = 0; // Always remember to reset you're global variables in-between test cases lol
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		solve();
	}
	return 0;
}

