#include <bits/stdc++.h>
using namespace std;

set<int> chkd;
int minimumSwaps(vector<int> arr) {
	const int n = arr.size();
	for (int i = 0; i < n; i++) {
		chkd.insert(i);
	}
	
	int curInd = 0, nextInd = arr[0] - 1;
	int jmps = 0, jmpsTot = 0;
	while (!chkd.empty()) {
		chkd.erase(curInd);
		jmps += 1;
		if (chkd.count(nextInd) == 0) {
			jmpsTot += jmps - 1;
			jmps = 0;
			curInd = *chkd.begin();
			nextInd = arr[curInd] - 1;
		} else {
			curInd = nextInd;
			nextInd = arr[curInd] - 1;
		}
	}
	return jmpsTot;
}

int main() {
	vector<int> v;
	int n;
	cin >> n;
	int t;
	for (int i = 0; i < n; i++) {
		cin >> t;
		v.push_back(t);
	}
	
	cout << minimumSwaps(v);
	return 0;
}

// AAAHHH, so you could just iterate through all of them in one loop, and if it isn't visited, then you
// have a separate function dfs through the loop and find the size of that loop, marking indexes as visited
// as it goes. Then you keep iterating through the top level loop until you find another unvisited node, or
// you reach the end of the array. This results in O(N), visiting each node at most twice. GOD, THIS IS WHAT
// I WANTED TO DO HOWD I NOT THINK OF IT FACK.
