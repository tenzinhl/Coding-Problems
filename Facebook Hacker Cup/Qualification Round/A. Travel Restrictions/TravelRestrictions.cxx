#include <bits/stdc++.h>
using namespace std;
#define ll long long

ofstream stout;
ifstream stin;

char inc[50];
char o[50];
char ans[50][50];

void solve() {
	int n;
	stin >> n;
	
	for (int i = 0; i < n; i++) {
		stin >> inc[i];
	}
	
	for (int i = 0; i < n; i++) {
		stin >> o[i];
	}
	
	for (int i = 0; i < n; i++) {
		ans[i][i] = 'Y'; // You can always travel to own country
		
		for (int j = i + 1; j < n; j++) {
			if (o[j-1] == 'Y' and inc[j] == 'Y' and ans[i][j-1] == 'Y') {
				ans[i][j] = 'Y';
			} else {
				ans[i][j] = 'N';
			}
		}
		
		for (int j = i - 1; j >= 0; j--) {
			if (o[j + 1] == 'Y' and inc[j] == 'Y' and ans[i][j + 1] == 'Y') {
				ans[i][j] = 'Y';
			} else {
				ans[i][j] = 'N';
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			stout << ans[i][j];
		}
		stout << '\n';
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	stout.open("output.txt"); // standard out
	stin.open("input.txt"); // standard in
	
	int t;
	stin >> t;
	for (int i = 1; i <= t; i++) {
		stout << "Case #" << i << ": \n";
		solve();
	}
	return 0;
}

