#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9

/**
 * Based off of typewriter example from 
 * http://www.cplusplus.com/reference/cstdio/getchar/
 * Playing around to be able to see how console application
 * could get realtime input.
 */

int main()
{
	char c;
	puts("Enter text. Include a dot ('.') in a sentence to exit:");
	do {
		c = getchar();
		putchar(c); 
		// Puts to stdout, which is flushed when you hit enter
		// echoing whatever the user had typed before the first period.
	} while (c != '.');
	// I am still confused on how it doesn't just insta terminate once the first
	// period is reached?
	cout << "do-while loop has exited" << endl;
	return 0;
}

