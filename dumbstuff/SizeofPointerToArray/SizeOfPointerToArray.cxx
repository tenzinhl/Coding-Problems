#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9

int main()
{
	int *a = new int[10];
	int b[10];
	cout << "Size of pointer to array of 10 integers: " << sizeof(a) << endl; // Outputs 8
	cout << "Size of array of 10 integers: " << sizeof(b) << endl; // Outputs 40
	delete a;
	a = nullptr;
	return 0;
}
// So size of pointer to int is actually larger than the size of an int. Makes
// sense I guess since a pointer holds a memory address, and you'd want more than
// 4 bytes of usable addresses haha. Point is though, can't use sizeof(pointer to array)
// in the sameway you can sizeof(arrayName).
