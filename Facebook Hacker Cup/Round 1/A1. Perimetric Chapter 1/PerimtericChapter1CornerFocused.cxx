#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9
#define N (int) 1e6 + 8
const int MOD = (int) 1e9 + 7;

string OUTPUT_FILE = "output.txt";
string INPUT_FILE = "perimetric_chapter_1_input.txt";
ofstream stout;
ifstream stin;

int n, k, w;
ll l[N], h[N], p[N];
ll al, bl, cl, dl, ah, bh, ch, dh;
void solve() {
	stin >> n >> k >> w;
	
	for (int i = 0; i < k; i++) {
		stin >> l[i];
	}
	stin >> al >> bl >> cl >> dl;
	for (int i = k; i < n; i++) {
		l[i] = (al * l[i-2] + bl * l[i-1] + cl) % dl + 1;
	}
	
	for (int i = 0; i < k; i++) {
		stin >> h[i];
	}
	
	stin >> ah >> bh >> ch >> dh;
	for (int i = k; i < n; i++) {
		h[i] = ((ah * h[i-2] + bh * h[i-1] + ch) % dh) + 1;
	}
	
	p[0] = 2 *(w + h[0]);
	ll mh = 0, ml = 0;
	ll ans = p[0];
	for (int i = 1; i < n; i++) {
		mh = 0;
		ml = 0;
		for (int r = 1; r <= w; r++) {
			if (i - r < 0 or l[i-r] + w < l[i]) break;
			ml = max(ml, l[i-r]);
			mh = max(mh, h[i-r]);
		}
		p[i] = p[i-1];
		if (h[i] > mh) p[i] += (h[i] - mh) * 2;
		p[i] += min((ll)w, l[i] - ml) * 2;
		p[i] %= MOD;
		ans = (ans * (ll) p[i]) % MOD;
	}
	
	// for (int i = 0; i < n; i++) {
		// cout << "#" << i << ": " << l[i] << " " << h[i] << " " << p[i] << endl;
	// }
	
	stout << ans << endl;
	return;
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

/* OMFG! I INPUT MY TEST CASES WRONG AND JUST SPENT LIKE 30-40 MINUTES
 * DEBUGGING A FAKE ISSUE FOCKS SAKE. godd...*/
/* Mistakes:
 * 	-Typing error, used bl instead of bh while copying equation. PAY MORE ATTENTION
 * 	to WHAT YOU'RE TYPING. I literally had it right after an hour, this mistake
 * 	cost me like an hour. Pay attention.
 * 	-(Smaller) Remember to modulus at every step if you have to work with modulus
 * 	answers. Overflow may appear where you don't expect*/
