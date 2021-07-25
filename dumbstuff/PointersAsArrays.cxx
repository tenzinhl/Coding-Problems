#include <bits/stdc++.h>
using namespace std;

int main()
{
	int* t = NULL; //Fred said good habit to have pointers be of value NULL when not used.
	t = new int [50]; //Should be equivalent to an array of 50 ints?
	//Just looked it up, "new" operator returns a pointer to the object
	//or first object of an array that it just allocated. That's why t
	//must be of type int* (a pointer).
	for (int i = 0; i < 50; i++) {
		t[i] = i;
	}
	cout << t;
	return 0;
}

