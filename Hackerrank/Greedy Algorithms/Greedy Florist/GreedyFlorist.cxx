#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9

int getMinimumCost(int k, vector<int> c) {
	int ans = 0;
	sort(c.begin(), c.end(), greater<int>());
	for (int i = 0; i < c.size(); i++) {
		ans += c[i] * (i / k + 1);
	}
	return ans;
}

/* WHY WAS this a "Medium" problem LOL.*/
int main()
{
	return 0;
}

