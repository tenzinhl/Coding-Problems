#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9

int maxMin(int k, vector<int> arr) {
	sort(arr.begin(), arr.end());
	int ans = (int) 1e9;
	for (int i = 0; i < arr.size() - k + 1; i++) {
		ans = min(ans, abs(arr[i] - arr[i+ k - 1]));
	}
	return ans;
}

// Yeah, greedy algorithm problems are pretty smoov.
int main()
{
	return 0;
}

