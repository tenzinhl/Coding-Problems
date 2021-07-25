#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9

int maximumToys(vector<int> prices, int k) {
	int toyCnt = 0;
	sort(prices.begin(), prices.end());
	int i = 0;
	while (k >= prices[i]) {
		toyCnt += 1;
		k -= prices[i];
		i++;
	}
	return toyCnt;
}

int main()
{
	return 0;
}

