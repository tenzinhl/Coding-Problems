#include <iostream>
#include <string>

using namespace std;
/* This is a test to work with pointers and strings. The goal of this program
 * is to reverse a string with two pointers. */
 
void swap(char *a, char *b) {
	char t = *b;
	*b = *a;
	*a = t;
}
//apparently I was unintentionally overloading swap() lol, as it already
//exists in the STL.

int main()
{
	string s;
	cin >> s;
	
	char *p1, *p2;
	p1 = &s[0];
	p2 = &s[s.size() - 1];
	for (long long unsigned int i = 0; i < s.size() / 2; i++) {
		swap(p1++, p2--);
	}
	
	cout << s;
	return 0;
}

//YO this works! Although the internet warns that pointers to string elements
//may be invalidated by things as simple as passing the string into STL functions.
