#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9

void printBinary(unsigned long long number) {
	cout << bitset<64>(number) << endl;
}

void set_spaces(unsigned long long* aisle, int index, unsigned short new_spaces) {
	if (new_spaces > 0x3ff) {
		return;
	}
	unsigned long long a = 0xffff'ffff'ffff'ffff;
	unsigned long long b = 0x3ff;
	a = a ^ (b << index * 16);
	*aisle = *aisle & a; // aisle will now have spaces of designated section zeroed
	*aisle = *aisle | ( (unsigned long long) new_spaces << index * 16);
	return;
}

void toggle_space (unsigned long long* aisle, int index, int space_index) {
	unsigned long long toggle_bit = 1 << (space_index + (index * 16));
	*aisle = *aisle ^ toggle_bit;
}

unsigned short num_items(unsigned long* aisle, int index) {
	unsigned long long section = *aisle >> (index * 16);
	unsigned short cnt = 0;
	for (int i = 0; i < 10; i++) {
		if (section & 1) {
			cnt++;
		}
		section >>= 1;
	}
	return cnt;
}

void add_items(unsigned long* aisle, int index, int n) {
	unsigned long long section_to_add = 0;
	unsigned long long section = *aisle >> (index * 16);
	for (int i = 9; i >= 0 and n > 0; i--) {
		if (!(section & (1 << i))) {
			n--;
			section_to_add += 1;
		}
		section_to_add <<= 1;
	}
	
	section_to_add <<= index * 16;
	*aisle = section_to_add | *aisle;
}

int main()
{
	return 0;
}

