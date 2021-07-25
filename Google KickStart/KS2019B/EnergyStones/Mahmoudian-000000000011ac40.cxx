// In the name of God

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <deque>
#include <assert.h>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <stdio.h>
#include <string.h>
#include <utility>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <complex>

using namespace std;

#define rep(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<typename T> inline bool smin(T &a, const T &b)   { return a > b ? a = b : a;    }
template<typename T> inline bool smax(T &a, const T &b)   { return a < b ? a = b : a;    }

typedef long long LL;

const int N = (int) 2e4 + 4, mod = (int) 0;
int s[N], e[N], l[N], o[N];
int cmp(int x, int y) {
	int xe = e[x] + e[y] - l[y] * s[x];
	int xy = e[x] + e[y] - l[x] * s[y];
	return xe > xy;
}
int dp[N], odp[N];
int main() {
	int tc;
	cin >> tc;
	for (int tt = 1; tt <= tc; ++tt) {
		cout << "Case #" << tt << ": ";
		int n;
		cin >> n;
		for (int j = 0; j < n; ++j) {
			cin >> s[j] >> e[j] >> l[j];	
			o[j] = j;
		}
		memset(dp, 0, sizeof dp);
		memset(odp, 0, sizeof odp);
		sort(o, o + n, cmp);
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			int j = o[i];
			sum += s[j];
			for (int secs = 0; secs <= sum; ++secs) odp[secs] = dp[secs];
			for (int secs = s[j]; secs <= sum; ++secs) {
				int en = e[j] - (secs - s[j]) * l[j];
				if (en <= 0) continue;
				dp[secs] = max(dp[secs], odp[secs - s[j]] + en);
			}
		}
		int res = 0;
		for (int j = 0; j < N; ++j) res = max(res, dp[j]);
		cout << res << '\n';
	}
}

















