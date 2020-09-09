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

int n, k, w;
int l[N], h[N], p[N];
int al, bl, cl, dl, ah, bh, ch, dh;
unordered_map<int, int> ch; // stores current max height of column at given x coord
void solve() {
	cin >> n >> k >> w;
	
	for (int i = 0; i < k; i++) {
		cin >> l[i];
	}
	cin >> al >> bl >> cl >> dl;
	for (int i = k; i < n; i++) {
		l[i] = ((al * l[i-2] + bl * l[i-1] + cl) % dl) + 1;
	}
	
	for (int i = 0; i < k; i++) {
		cin >> h[i];
	}
	
	cin >> ah >> bh >> ch >> dh;
	for (int i = k; i < n; i++) {
		h[i] = ((ah * h[i-2] + bl * h[i-1] + ch) % dh) + 1;
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < w; j++) {
			if (h[i] > ch[i + j]) {
				ch[i+j] = h[i];
			}
		}
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

