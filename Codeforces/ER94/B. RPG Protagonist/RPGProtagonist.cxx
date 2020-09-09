#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9
int p, f;
int cnts, cntw, s, w;
void solve() {
	cin >> p >> f >> cnts >> cntw >> s >> w;
	long long ans = 0;
	// So we only have to write logic once. Written as if s is smaller
	if (w < s) {
		swap(s, w);
		swap(cnts, cntw);
	}
	if (f > p) {
		swap(f, p);
	}
	ll wp = 0, wf = 0;
	int ts = cnts, tw = cntw, sp = 0, sf = 0;
	while (ts > 0 and wp + s <= p) {
		wp += s;
		ts -= 1;
		sp += 1;
	}
	while (ts > 0 and wf + s <= f) {
		wf += s;
		ts -= 1;
		sf += 1;
	}
	ts = sf + sp;
	// cout << sp << " " << sf << " " << ts << endl;
	for (int i = sf; (i * s) <= f and i <= ts; i++) {
		wp = (ts - i) * s;
		wf = i * s;
		// cout << "sf: " << i << " " << wp << " " << wf << endl;
		tw = min((p - wp) / w + (f - wf) / w, (ll)cntw);
		ans = max((ll)ts + tw, ans);
	}
	cout << ans << "\n";
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

// if (s < w) {
// if (s * cnts > p + f) {
	// ans = p / s + f / s;
	// cout << ans;
	// return;
// }
// } else {
// if (w * cntw > p + f) {
	// ans = p / w + f / w;
	// cout << ans;
	// return;
// }
// }

/* Not done yet, BUT STOP PLACING FING += EVERYWHERE. ITS SO OFTEN THE CAUSE
 * OF HEADACHES. Also, STOP USING WRONG VARIABLE IN FOR LOOP. I was using sf
 * when FUCKIN "i" is the loop variable you dumbass.
 * 
 * Another error: WATCH out, especially in weighted knapsack like problems, where
 * YOURE USING < AND <=. IT MATTERS. Omg, this whole time it was another "<" that should
 * have been "<=" hidden in a for loop logic.
 * */
