#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9

int main()
{
	int n = 1;
	if (*(char*)&n == 1) {
		cout << "little endian";
	} else {
		cout << "big endian";
	}
	return 0;
}

