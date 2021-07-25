#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	for (int i = 0; i < 5; i++) {
		cout << i << endl;
		i = 5;
	} // For this type of loop it's passed by reference!!. Update: not really, i is just a variable in the loops scope.
	// Thus, will only loop once as i gets changed.
	
	int ar[5] = {0, 0, 0, 0, 0};
	
	for (auto a : ar) {
		a = 5;
	} // Range-based for loops pass by value!!!
	cout << ar[2] << endl; // Will cout: 0
	return 0;
}

