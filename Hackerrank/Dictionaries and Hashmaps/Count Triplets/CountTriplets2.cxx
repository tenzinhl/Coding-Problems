#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9

long countTriplets(vector<long> arr, long r) {
	if (r >= (long long) 1e5) {
		return 0;
	}
	unordered_map<long, long> numCount;
	unordered_map<long, long> map2; // I honestly don't know what to call this variable
	long b;
	long ans = 0;
	for (int i = arr.size() - 1; i >=0; i--) {
		b = arr[i] * r;
		if (numCount.count(b)) {
			map2[arr[i]] += numCount[b];
		}
		
		if (r == 1 and numCount.count(arr[i])) {
			ans += numCount[arr[i]] * (numCount[arr[i]] - 1) / 2;
		} else if (map2.count(b)) {
			ans += map2[b];
		}
		numCount[arr[i]] += 1;
	}
	return ans;
}

int main()
{

	return 0;
}

