#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	int a = 100008;
	int b = a << 2;
	int c = a * 2;
	cout << "b: " << b << endl;
	cout << "c: " << c;
	return 0;
}

// WAIT IM A DUMBASS. << 2 = * 4. omg.... Anyways yes, when allocating 
// an array for a binary tree, do the max number of leafs * 4, i.e.: << 2.
/* The reasoning here is that the binary tree needs the nearest power of two
 * greater than your LIM * 2 - 1. So the first multiplication ensures the array
 * size is greater than the nearest power of two, then the second *2 gives space
 * for the entire tree, (branch nodes and leaves combined).*/
