#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9

int main()
{
	// Commenting out the following two lines: warns that b is uninitialized (but not a). Uncommented, no unititialization warning is thrown.
	int c;
	cin >> c;
	int a, b;
	a = b;
	a += 1;
	return 0;
}

/* This code will compile perfectly fine without throwing warning that b is uninitialized. 
 * Serves as a warning that you should double check your code for uninitialization, as
 * compiler may not detect it in important scenarios.
 * 
 * In fact I've had this happen to me before, but never really noticed till today
 * August 27th 2020. When implementing binary search there have been times where it didn't
 * tell me either a lb or ub was... nvm. I'm not sure. BUT REGARDLESS, it is super key
 * now to */
