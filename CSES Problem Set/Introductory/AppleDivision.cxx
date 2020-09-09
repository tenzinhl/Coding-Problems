#include <bits/stdc++.h>
using namespace std;

/* Apples, so I thought of a greedy solution, but I haven't thought long
 * enough or hard enough to prove if it always is optimal. But F it, it seems good
 * in my head, wo I'm just gonna try and submit it and see if it passes.
 *
 * So my idea is to sort the apple values then put the next sized apple in
 * the smaller of two stacks until I've used them all up. I can't think of 
 * a situation where this doesn't work.
 * 
 * Okay, so this totally doesn't work lol. But maybe we can have another
 * function that swaps apples between the two stacks afterwards, aiming
 * to balance the stacks as much as possible.*/

long long apples[20];

vector <long long> stack1;
vector <long long> stack2;
long long stack1value;
long long stack2value;
int main()
{
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> apples[i];
	}
	
	sort(apples, apples + n, greater<>());
	
	for (int i = 0; i < n; i++) {
		if (stack1value > stack2value) {
			stack2value += apples[i];
			stack2.insert(stack2.begin(), apples[i]);
		} else {
			stack1value += apples[i];
			stack2.insert(stack2.begin(), appl]es[i]);
		}
	}
	
	for (int i = 0; i < stack1.size(); i++) {
		for (int j = 0; j < stack2.size(); j++) {
			
		}
	}
	cout << abs(stack1value - stack2value);
	return 0;
}

