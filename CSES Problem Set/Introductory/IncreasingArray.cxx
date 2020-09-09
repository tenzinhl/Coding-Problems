#include <bits/stdc++.h>
using namespace std;


int main()
{
	int ar[200001];
	int n;
	long long a = 0;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> ar[i];
	}
	
	for (int i = 1; i < n; i++) {
		if (ar[i] >= ar[i-1]) {
			continue;
		}
		a += (ar[i-1] - ar[i]);
		ar[i] = ar[i-1];
	}
	
	cout << a;	
	return 0;
}

