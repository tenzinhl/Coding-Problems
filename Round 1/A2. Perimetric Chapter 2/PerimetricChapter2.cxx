#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9
#define N (int) 1e6 + 8
const int MOD = (int) 1e9 + 7;
string OUTPUT_FILE = "output.txt";
string INPUT_FILE = "input.txt";
ofstream stout;
ifstream stin;

int n, k, ac, bc, cc, dc;
ll l[N], w[N], h[N], p[N];
set<pair<int, int>> st;
void solve() {
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> l[i];
	}
	cin >> ac >> bc >> cc >> dc;
	for (int i = k; i < n; i++) {
		l[i] = (ac * l[i-2] + bc * l[i-1] + cc) % dc + 1;
	}
	
	for (int i = 0; i < k; i++) {
		cin >> w[i];
	}
	cin >> ac >> bc >> cc >> dc;
	for (int i = k; i < n; i++) {
		w[i] = (ac * w[i-2] + bc * w[i-1] + cc) % dc + 1;
	}
	
	for (int i = 0; i < k; i++) {
		cin >> h[i];
	}
	cin >> ac >> bc >> cc >> dc;
	for (int i = k; i < n; i++) {n
		h[i] = (ac * h[i-2] + bc * h[i-1] + cc) % dc + 1;
	}
	
	p[0] = (w[0] * 2 + h[0] * 2) % MOD;
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

