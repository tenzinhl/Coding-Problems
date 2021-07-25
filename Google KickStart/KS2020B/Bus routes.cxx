#include <bits/stdc++.h>
using namespace std;

int n;
long long x[1000];
long long d;

//a tale of making sure to use the right fing type, and to be aware that
//types go everywhere holy crap. I did a good job of having the right idea
//for solving this problem though. Didn't trust myself and just go for it
//was an issue.

bool time(long long start) {	//missed putting longlong here as well. OMG
	long long cur = start;
	
	for (int i = 0; i < n; i++) {
		cur = ((cur + x[i] - 1) / x[i]) * x[i];
	}
	
	if (cur <= d) return true;
	else return false;
}
	
//HOLY SHIT, just realized the issue was that this function is set to return
//an int instead of a long long. Compiler doesn't throw error because it
//just does implicit conversion. f me dude.
long long solve() {
	cin >> n >> d;
	
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	
	long long lb, ub, mb;
	lb = 1;
	ub = d;
	
	bool works;
	while (lb <= ub) {
		mb = (lb + ub)/2;
		works = time(mb);
		if (works)
			lb = mb + 1;
		else
			ub = mb - 1;
		}
	return ub;
} 

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	
	for (int i = 1; i <= t; i++) {
		long long ans = solve(); //had to change the type of ans to long long as well.
		cout << "Case #" << i << ": " << ans << "\n";
	}
	return 0;
}
