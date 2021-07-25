#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9

int minimumAbsoluteDifference(vector<int> arr) {
	sort(arr.begin(), arr.end());
	int ans = (int) 2e9 + 1;
	for (int i = 0; i < arr.size() - 1; i++) {
		ans = min(ans, abs(arr[i] - arr[i+1]));
	}
	return ans;
}

int main()
{
	return 0;
}

