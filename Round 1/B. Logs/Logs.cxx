#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9
#define LIM (int) 5e8 + 8
const int N = (int) 1e6 + 8;
string OUTPUT_FILE = "output.txt";
string INPUT_FILE = "dislodging_logs_input.txt";
ofstream stout;
ifstream stin;

int n, m, k, s, p[N], q[N];
// Checks if it is possible to light fuse by given time
int bgn[N], nd[N]; // stores begin and end index for given log driver

// Returns minimum distance (i.e.: time) that log driver would have to walk to reach log clusters at pos l through pos r, given starting pos "start"
int dist(int start, int l, int r) {
	return abs(r - l) + min(abs(start - l), abs(start - r));
}
bool isPossible(int t) {
	int chkd = 0;
	for (int i = 0; i < n and chkd < m; i++) {
		bgn[i] = chkd;
		nd[i] = chkd;
		if (abs(p[i] - q[chkd]) > t) {
			continue; // error was here, should continue instead of return false as next log driver may be able to reach
		} else {
			chkd += 1;
		}
		while(chkd < m and dist(p[i], q[bgn[i]], q[chkd]) <= t) {
			chkd += 1;
		}
	}
	if (chkd == m) {
		return true;
	} else {
		return false;
	}
}
// 
void solve() {
	stin >> n >> m >> k >> s;
	for (int i = 0; i < k; i++) {
		stin >> p[i];
	}
	int am, bm, cm, dm;
	stin >> am >> bm >> cm >> dm;
	for (int i = k; i < n; i++) {
		p[i] = ((ll)p[i-2] * am + (ll)p[i-1] * bm + cm) % (ll)dm + 1;
	}
	
	for (int i = 0; i < k; i++) {
		stin >> q[i];
	}
	stin >> am >> bm >> cm >> dm;
	for (int i = k; i < m; i++) {
		q[i] = ((ll)q[i-2] * am + (ll)q[i-1] * bm + cm) % (ll)dm + 1;
	}
	
	// sort positions of loggers and log clusters in increasing order for greedy algorithm
	sort(p, p + n);
	sort(q, q + m);
	// for (int i = 0; i < n; i++) {
		// cout << p[i] << " ";
	// }
	int lb, ub, mb;
	lb = 0;
	ub = 2 * LIM;
	while (lb <= ub) {
		 mb = (lb + ub)/2;
		 if (isPossible(mb)) {
			 ub = mb - 1;
		 } else {
			 lb = mb + 1;
		 }
	}
	
	stout << lb << endl;
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

// NICE! This problem has gone really smoothly (still not done, but I am pretty sure of error).
/* I truly believe I could have gotten this question that day if I had been more awake and the
 * problem statement had been in its final form. The original version is an unsolved problem lol,
 * literally Multiple travelling Salesmen (MTS) which is like a theoretical problem currently.*/

/* Yeah, error was what I thought it was. Key takeaway: OVERFLOW, OVRFLOW, OVERFLOW, I found it pretty
 * quickly thankfully (I am getting better). Even though this is all addition and subtraction
 * and there ostensibly shouldn't have been overflow issues, it was hidden in the input method, where
 * you have to MULTIPLY to get the input. Always look out for multiplication overflow.*/
