#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9

priority_queue<int> pq;
int main()
{
	// Commenting out the following two lines will cause compiler to detect that b is unitialized. WTF?!
	// int n;
	// cin >> n;
	// for (int i = 0; i < n; i++) {
		// pq.push(i);
	// }
	int c;
	cin >> c;
	int a = 0, b;
	// b += 1;
	a = b;
	// a++; // avoids "-Wunused-but-set-variable" warning
	if (a == b) { // using b in if statement will not cause detection.
		cout << "ha";
	}
	// cout << a; // This line will cause compiler to detect that b is uninitialized.
	return 0;
}

/* If you cout a variable compiler will always detect if it's unititialized.
 * What went wrong in Toys attempt 2 then? (tremovedCnt was uninitialized and compiler
 * did not throw warning).
 * */
