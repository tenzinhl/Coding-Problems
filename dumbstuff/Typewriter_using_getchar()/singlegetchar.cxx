#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
#define ll long long
#define INF (int) 2e9

int main()
{
	char c;
	puts("This program calls getchar() once, the purpose is to see if "
			"it just instantly terminates after getchar() is called");
	c = _getch();
	/* It doesn't. So my assumption is that nothing is put into the input
	 * buffer until you hit enter. At AND THEN all of the getchar() are called
	 * in whatever order they are supposed to be. Nice.
	 * 
	 * But unfortunately this means that this still doesn't solve my issue of
	 * not having to type enter to send input...*/
	return 0;
}

