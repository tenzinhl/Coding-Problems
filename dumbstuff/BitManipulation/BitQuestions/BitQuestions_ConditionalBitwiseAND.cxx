#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9


int main()
{
	unsigned int a = 15;
	if (a & (1 << 3)) { // Makes sense, since it'd evaluate to 8. And any value non-zero is "true".
		cout << "this worked";
	}
	
	if (-1) {
		cout << "\nNegative numbers pass conditionals"; // Makes sense, as bitwise it's non-zero
	}
	return 0;
}

