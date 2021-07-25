#include <bits/stdc++.h>
using namespace std;
#define ll long long

pair<long, long> *trees = new pair<long, long> [800000];

int main()
{
	trees[0] = make_pair(1, 2);
	cout << trees[0].second;
	delete[] trees;
	trees = NULL;
	return 0;
}

