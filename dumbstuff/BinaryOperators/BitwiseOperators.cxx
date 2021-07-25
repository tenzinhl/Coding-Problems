#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9

// Testing out and understanding binary operators
int main()
{
	// "&" operator does AND operation on every bit in both numbers. (AND operation returns 1 ONLY IF both bits are 1)
	int a = 5; // 101
	int b = 7; // 111
	int c = a & b; // 101 & 111 = 101;
	cout << c << endl; // outputs 5.
	return 0;
}

