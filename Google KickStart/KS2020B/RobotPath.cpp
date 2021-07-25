#include <bits/stdc++.h>
using namespace std;

#define SIZE 1000000000
//int ans; would have to pass 2 arguments, bad setup.
long long x[1001];
long long y[1001];
int multiplier[1001];
int depth = 0;
string program;		
	
void solve() {
	cin >> program;
	//program.push_back('Z'); //something I would have done to check when
							//the string terminated

	//char *curNode = &program[0];
	for (auto c : program) {
		if (c == 'N')
			y[depth] -= 1;
		if (c == 'S')
			y[depth] += 1;
		if (c == 'W')
			x[depth] -= 1;
		if (c == 'E')
			x[depth] += 1;
		if (c >= '0' && c <= '9') {
			depth += 1;
			multiplier[depth] = c - '0';
		}
		if (c == ')') {
			x[depth-1] += (multiplier[depth] * x[depth]) % SIZE; //GREAT JOB, this was the overflow issue. % solves it.
			y[depth-1] += (multiplier[depth] * y[depth]) % SIZE;
			x[depth] = 0;
			y[depth] = 0;
			multiplier[depth] = 0; //technically redundant, but helps clarify purpose.
			depth -= 1;
		}
	}
	long long xf, yf;
	
	x[0] = x[0] % 1'000'000'000;
	y[0] = y[0] % 1'000'000'000;
	
	if (x[0] < 0)
		xf = 1'000'000'000 + x[0] + 1;
	else xf = 1 + x[0];
	if (y[0] < 0)
		yf = 1'000'000'000 + y[0] + 1;
	else yf = 1 + y[0];
	
	cout << xf << " " << yf;
	
	x[0] = 0;
	y[0] = 0;
}

//LET'S FRIGGIN GO BABY. I knew how I wanted to solve this one, it was
//just the implementation that had me stuck. Came back fresh today and
//nailed it! Let's GOOO. I'm getting WA on the second test set, pretty
//sure that it's due to overflow, but I can't figure out where. I changed
//a whole bunch of variables to long long but it still hasn't fixed it.
//Potentially something wrong with my modulo math?
		
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": ";
		solve();
		cout << "\n";
	}
	
	return 0;
}

//complex idea involving pointers that I considered implementing to practice
//pointer stuff. TOO hard honestly, and also finicky and not even necessarily
//the right approach as strings will be reallocated in memory as they grow

//void loop(int *&node, int factor) {
	//long long dx, dy;
	
	//dx = 0;
	//dy = 0;
	//char c;
	
	//while (*node != 'Z') { //while logic used to be (*node != '(' and *node != ')')
		//if (c >= '0' && c <= '9')
			//pair a = loop(&node + 2, c - '0');
			//dx += loop.first;
			//dy += loop.second; 
		//if (c == 'N')
			//dy -= 1;
		//if (c == 'S')
			//dy += 1;
		//if (c == 'W')
			//dx -= 1;
		//if (c == 'E')
			//dx += 1;
		//if (c == ')') {
			//pair p(dx * factor,dy * factor); 
			//return p;
		//}
		//node += 1;
		//c = *node;
	//}
	//return {dx, dy}
//}
