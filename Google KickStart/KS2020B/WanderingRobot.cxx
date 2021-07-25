#include <bits/stdc++.h>
using namespace std;

int w, h, l, u, r, d;
long double log2facts[50002];

void log2fact() {
	log2facts[0] = 0.0;
	log2facts[1] = 0.0;
	for (int i = 2; i <= 50001; i++) {
		log2facts[i] = log2facts[i-1] + log2(i);
	}
}

void solve() {
	cin >> w >> h >> l >> u >> r >> d;
	
	int x = l - 1;
	int y = d + 1;
	//long double lp1 = 0;
	long double path1 = 0;
	int distance;
	//omg I had a huge error in the ways of my math lol.
	while (x > 0 and y <= h) {
		distance = x + y - 2;
		path1 += pow(2.0, log2facts[distance] - log2facts[x-1] - log2facts[y-1]
		- distance);
		x--;
		y++;
	}
	
	//if (lp1 == 0) path1 = 0; //add this line to account for no available path, cuz issue is 2^0 = 1.
	//else path1 = pow(2.0, lp1);
	
	x = r + 1;
	y = u - 1;
	//long double lp2 = 0;
	long double path2 = 0;
	
	//FOUND THE ERROR LOL, the loop conditions are wrong. Error code
	//arose from trying to write over memory that was reserved by OS
	//(pretty sure at least)
	while (x <= w and y > 0) { 
		distance = x + y - 2;
		path1 += pow(2.0, log2facts[distance] - log2facts[x-1] - log2facts[y-1]
		- distance);
		x++;
		y--;
	}
	
	//if (lp2 == 0) path2 = 0;
	//else path2 = pow(2.0, lp2);

	cout << path1 + path2 << "\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	log2fact();
	
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}

//current issue is special logic needs to be implemented for calculating
//the probability for key squares on last row / last column, because for
//those the squares don't have a 50/50 chance as there is only one possible
//movement next turn.
