#include <bits/stdc++.h>
using namespace std;
#define ll long long

long n, x, p[200000], gondolas[200001], cnt;
short passengers[200001];
// multiset<long> gs;

int main()
{
	cin >> n >> x;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	
	sort(p, p + n, greater<long>());
	
	long j, req = 1;
	
	for (long i = 0; i < n; i++) {
		for (j = 0; j < req; j++) {
			if (gondolas[j] + p[i] <= x and passengers[j] < 2) {
				gondolas[j] += p[i];
				passengers[j] += 1;
				break;
			} 
		}
		
		if (j == req) {
			req++;
			gondolas[req - 1] = p[i];
		}
	}
	
	cout << req;
	return 0;
}

// Goddamn it (or I guess I should be proud). So I totally had the right idea
// the key is to turn this from O(n^2) (here assuming each person fills a gondola,
// we will need to iterate over each person, and then over each existing gondola,
// creating a triangle, which is proportional to (n^2) into O(nlogn) using a self-balancing
// binary search tree. So that's what I need to learn basically. OMG I was even more correct
// by considering the use of a multiset to keep track of bins. Apparently sets are self-balancing
// binary search trees. Damn... I'm upset that I have the right idea and didn't know how
// to implement it. But at the same time I should be happy that I'm thinking in the right way.
// Eyy! I even calculated big(O) correctly according to geeks for geeks

// DUMBASS! The problem statement says only 2 children at most per gondola.
