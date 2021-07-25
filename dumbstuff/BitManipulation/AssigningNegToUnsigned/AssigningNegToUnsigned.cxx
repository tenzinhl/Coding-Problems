#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9

void printBitsUInt(unsigned int x) {
	cout << "Bit representation of number: \n";
	for (int i = 31; i >= 0; i--) {
		cout << ((x >> i) & 1);
	}
	cout << endl;
}

int main()
{
	unsigned int y = -2;
	
	printBitsUInt(y);
	
	// Section from CSE 351 lab1b
	float a = 1.0 + ((float) (1 << 22));
	float b = 1.0 + ((float) (1 << 23));
	float c = 1.0 + ((float) (1 << 24));

	cout << "a: " << a << ", b: " << b << ", c: " << c << endl;
	cout << "sizeof(float) = " << sizeof(float) << endl;
	return 0;
}

