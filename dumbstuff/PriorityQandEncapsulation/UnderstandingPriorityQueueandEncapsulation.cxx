#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9

int main()
{
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 5; i >= 0; i--) {
		pq.push(i);
	}
	
	for (int i = 0; i < 6; i++) {
		cout << pq.top() << " ";
		pq.pop();
	}
	// pq.clear();
	// Okay, so encapsulator classes do not have functions that are not specified in the docs,
	// even if the container it is based on supports that method. Currently, the recommendation
	// is to just reassign the priority queue variable by making a new priority queue and assigning it
	// to the original variable, like so:
	pq = priority_queue <int, vector<int>, greater<int>>();
	if (pq.empty()) cout << "true";
	return 0;
}

