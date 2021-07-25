#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9

int ar[50];
int& getReference(int i) {
	return &ar[i];
}
int main()
{
	for (int i = 0; i < 50; i++) {
		ar[i] = i;
	}
	
	int a = getReference(29);
	cout << a << endl;
	a = 5;
	cout << ar[29];
	return 0;
}

