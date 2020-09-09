#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
string a, b;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	for (int h = 1; h <= t; h++) {
		cin >> n >> a >> b;
		vector <int> ops;
		int li, ri;
		char c;
		for (int i = n - 1; i >= 0; i--) {
			if (a[0] == b[i]) {
				ops.push_back(1);
			}
			ops.push_back(i + 1);
			for (int j = 0; j <= i; j++) {
				if (a[j] == '0') {
					a[j] = '1';
				} else if (a[j] == '1') {
					a[j] = '0';
				}
			}
			li = 0, ri = i;
			while (li < ri) {
				c = a[li];
				a[li] = a[ri];
				a[ri] = c;
				li++, ri--;
			}
		}
		cout << ops.size() << ' ';
		for (int x : ops) {
			cout << x << ' ';
		}
		cout << '\n';
	}
	return 0;
}

