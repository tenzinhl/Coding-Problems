#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9

vector<int> q;
void shiftRight(int ind, int a) { // shifts value at given index to the right given number of times
	for (int i = 0; i < a; i++) {
		swap(q[ind + i], q[ind + i + 1]);
	}
	return;
}

void pArray() {
	for (auto &i : q) {
		cout << i << " ";
	}
	return;
}
void solve() {
	int n, changeCnt = 0;
	q.clear();
	cin >> n;
	int t;
	for (int i = 0; i < n; i++) {
		cin >> t;
		q.push_back(t);
	}
	
	for (int i = 0; i < n; i++) {
		if (q[i] - 1 - i > 2 ) {
			cout << "Too chaotic\n";
			return;
		}
	}
	
	for (int i = n - 1; i >= 0; i--) {
		while (q[i] > i + 1) { // may have to shift a given index more than once, i.e.: 3 2 1 -> 2 1 3 -> 1 2 3
			changeCnt += q[i] - i - 1; 
			shiftRight(i, q[i] - i - 1);
		}
	}
	cout << changeCnt << "\n";
	return;
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

/*
1
5
2 1 5 3 4

1
8
1 2 5 3 7 8 6 4

2
8
5 1 2 3 7 8 6 4
8
1 2 5 3 7 8 6 4
*/
