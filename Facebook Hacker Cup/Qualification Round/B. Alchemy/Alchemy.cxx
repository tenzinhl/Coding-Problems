#include <bits/stdc++.h>
using namespace std;
#define ll long long

string OUTPUT_FILE = "output.txt";
string INPUT_FILE = "input.txt";
ofstream stout;
ifstream stin;

void solve() {
	int n;
	string s;
	
	stin >> n >> s;
	
	ll acnt = 0, bcnt = 0;
	for (char c : s) {
		if (c == 'A') {
			acnt += 1;
		} else {
			bcnt += 1;
		}
	}
	
	if (abs(acnt - bcnt) == 1) {
		stout << "Y \n";
	} else {
		stout << "N \n";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	stin.tie(0);
	
	stout.open(OUTPUT_FILE);
	stin.open(INPUT_FILE);
	
	int t;
	stin >> t;
	for (int i = 1; i <= t; i++) {
		stout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}

