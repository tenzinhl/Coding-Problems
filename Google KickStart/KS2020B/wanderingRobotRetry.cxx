#include <bits/stdc++.h>
using namespace std;
//Finally figured out the issue, goddamnit! The largest lfac we can need
//is x+y-2 right? so that means that size needs to be at least Max W + maxH
//which will be at least 200,000, Scott Wu just made it 1000100 lol.
#define SIZE 200000
long w, h, l, u, r, d;

long double l2facts[SIZE+1];

void l2fact() {
	l2facts[0] = 0;
	l2facts[1] = 0;
	for (int i = 2; i <= SIZE + 1; i++) {
		l2facts[i] = l2facts[i-1] + log2(i);
	}
}

void solve() {
	cin >> w >> h >> l >> u >> r >> d;
	
	int x = l - 1;
	int y = d + 1;
	
	long double blp = 0;
	long double sxp;
	
	//iterating over bottom left key squares.
	while (x > 0 and y <= h) {
		if (x > 1 and y == h) {
			y--;
			while (x > 0) {
				sxp = l2facts[x + y - 2] - l2facts[x-1] - l2facts[y-1] - (x + y - 2);
				blp += pow(2.0, sxp - 1);
				x--;
			}
			break;
		}
		sxp = l2facts[x + y - 2] - l2facts[x-1] - l2facts[y-1] - (x + y - 2);
		blp += pow(2, sxp);
		x--, y++;
	}
	
	x = r + 1;
	y = u - 1;
	//iterating over top right key squares.
	while (x <= w and y > 0) {
		if (x == w and y > 1) {
			x--;
			while (y > 0) {
				sxp = l2facts[x + y - 2] - l2facts[x-1] - l2facts[y-1] - (x + y - 2);
				blp += pow(2.0, sxp - 1);
				y--;
			}
			break;
		}	
		sxp = l2facts[x + y - 2] - l2facts[x-1] - l2facts[y-1] - (x + y - 2);
		blp += pow(2.0, sxp);
		x++, y--;
	}
	
	cout << fixed << setprecision(9);
	cout << blp << "\n";
}

int main()
{
	int t;
	cin >> t;
	
	l2fact();
	
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}

