#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9

void printHeap(vector<int> &v) {
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	
	vector<int> v;
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		v.push_back(temp);
	}
	
	make_heap(v.begin(), v.end());
	cout << "initial heap: ";
	printHeap(v);
	cout << endl;
	return 0;
}
/*
7
1 2 3 4 5 6 7 
output: 7 5 6 4 2 1 3

7
7 6 5 4 3 2 1
output: 7 6 5 4 3 2 1

7
1 4 5 3 2 6 7
output: 7 4 6 3 1 2 5

So I was hoping I'd be able to find the median from a heap, but obviously that
* would require the values to follow a strict ordering, which would require a
* tree like structure, like a set. ugh... guess I'm gonna gave to go with the
* weird iterator moving multiset idea to solve that hackerrank problem.
*/
