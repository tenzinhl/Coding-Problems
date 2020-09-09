#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define LIM (int) 1e5 + 8

int cnt[LIM];
int pairs[LIM];
int fours[LIM];
int tpairs;
int tfours;

void add(int a) {
	cnt[a] += 1;
	if (cnt[a] == 2) {
		pairs[a] += 1;
		cnt[a] = 0;
		tpairs += 1;
		if (pairs[a] == 2) {
			fours[a] += 1;
			pairs[a] = 0;
			tpairs -= 2;
			tfours += 1;
		}
	}
	return;
}

void subtract(int a) {
	cnt[a] -= 1;
	if (cnt[a] < 0) {
		pairs[a] -= 1;
		cnt[a] += 2;
		tpairs -= 1;
		if (pairs[a] < 0) {
			fours[a] -= 1;
			pairs[a] += 2;
			tpairs += 2;
			tfours -= 1;
		}
	}
	return;
}

bool possible() {
	if (tfours <= 0) {
		return false;
	}
	if (tfours >= 2) {
		return true;
	}
	if (tpairs >= 2) {
		return true;
	}
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	int a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		add(a);
	}
	
	int q;
	cin >> q;
	char e;
	for (int i = 0; i < q; i++) {
		cin >> e >> a;
		if (e == '+')
			add(a);
		if (e == '-')
			subtract(a);
		if (possible()) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}

