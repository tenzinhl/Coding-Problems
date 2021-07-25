#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9

void printBinary(unsigned long long number) {
	cout << bitset<64>(number) << endl;
}

void set_section(unsigned long long* aisle, int index, unsigned short new_section) {
	unsigned long long a = 0xffffffffffffffff;
	unsigned long long b = 0xffff;
	b <<= (index * 16);
	a = a ^ b;
	unsigned long long c = (unsigned long long) new_section << (index * 16);
	unsigned long long aisleWithSectionCleared = *aisle & a; // zeroes the desired section
	*aisle = aisleWithSectionCleared | c;
}

int main()
{
	unsigned ll aisle = 0xae68'ae68'ae68'ae68;
	
	set_section(&aisle, 2, 0xf0f0);
	printBinary(aisle);
	return 0;
}

