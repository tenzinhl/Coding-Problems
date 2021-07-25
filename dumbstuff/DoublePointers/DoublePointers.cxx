#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9

int main()
{
	int x = 0;
	int *p1 = &x;
	// int **p2 = &x; // Compilation fails; "cannot convert int* to int** in initialization"
	int **p2 = (int**) &x; // You can typecast it and get it to work.
	cout << p1 << " " << p2;
	return 0;
}

