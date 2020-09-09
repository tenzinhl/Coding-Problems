#include <bits/stdc++.h>
#define ll long long
using namespace std;


//apple division with hints. Attempting recursively. This worked like a charm,
//gg.
int n;
ll apples[20];

ll findMin(ll sum1, ll sum2, int i) {
	if (i == n) {
		return abs(sum1 - sum2);
	} else {
		return min(
		findMin(sum1 + apples[i], sum2, i + 1),
		findMin(sum1, sum2 + apples[i], i + 1)
		);
	}
}

int main()
{
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		cin >> apples[i];
	}
	
	cout << findMin(0, 0, 0);
	return 0;
}

