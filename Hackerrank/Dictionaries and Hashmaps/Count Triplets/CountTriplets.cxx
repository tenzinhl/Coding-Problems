#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9

long countTriplets(vector<long> arr, long r) {
	if (r >= (long long) 1e5) {
		return 0;
	}
	unordered_map<long, int> numCount;
	long ans = 0;
	long long b, c;
	for (int i = arr.size() - 1; i >= 0; i--) {
		b = arr[i] * r;
		c = b * r;
		if (r == 1 and numCount.count(arr[i])) {
			ans += (long long)(numCount[arr[i]]) * (numCount[arr[i]] - 1) / 2;
		} else if (numCount.count(b) and numCount.count(c)) {
			ans += (long) numCount[b] * numCount[c];
		}
		numCount[arr[i]] += 1;
	}
	return ans;
}

int main()
{
	return 0;
}

/* Ah right, I forgot to account for the fact that the three indices in the triplet
// need to be in strictly increasing order, and my unordered_map method will pull
// numbers from anywhere in the vector. 
* 
* The solution should be pretty simple, we just iterate through the array backwards,
* pushing to the unordered_map as we go, checking at each iteration if we can form
* a new triplet.
* 
* Woops, I'm still dumb. My logic for on line 19 doesn't account for strict ordering
* of the indices. The logic could be pulling numbers from anywhere. So to fix this, instead
* of just keeping the count of the numbers, we also need to keep the count of the number of
* ways to correctly form a geometric pair for a given value (i.e.: for value x, how many 
* x * r appear after corresponding indices of x. Ez enough to do. 
* 
* We keep adding to that second map as we go with the former logic. We check
* the number of x * r currently in the map, and then we add them to the second
* map. Then for each x, we check the second map for the value of x *r and add that
* to our ans. EZ clap.*/

//161700
