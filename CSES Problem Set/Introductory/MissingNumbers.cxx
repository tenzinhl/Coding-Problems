#include <bits/stdc++.h>
using namespace std;

bool ex[1000001];

int main() {
	
	int n;
	cin >> n;
	
	int cur;
	for (int i = 1; i <= n; i++) {
		cin >> cur;
		ex[cur] = true;
	}
	
	bool found = false;
	int m = 1;
	while (found == false) {
		if (ex[m] == false) {
			cout << m;
			found = true;
		}
		m++;
	}
	return 0;
}

