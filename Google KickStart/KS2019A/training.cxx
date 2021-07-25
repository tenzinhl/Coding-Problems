#include <bits/stdc++.h>
using namespace std;

int n, p, s[100000], difs[100000], hours[10000];
long long sum, a, b, best, cur;

void dcalc() {
	for (int i = 0; i < n - 1; i++) {
		difs[i] = s[i+1] - s[i];
	}
}
	
void solve() {
	cin >> n >> p;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	
	sort(s, s + n);
	
	sum = 0;
	for (int i = 0; i < p; i++) {
		sum += s[i];
	}
	
	best = (s[p - 1] * p) - sum;
	
	for (int i = 0; i + p - 1 < n; i++) {
		cur = (s[i + p - 1] * p) - sum;
		best = min(best, cur);
		sum = sum - s[i] + s[i + p];
	}
	
	cout << best << "\n";
}

int main()
{
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}

