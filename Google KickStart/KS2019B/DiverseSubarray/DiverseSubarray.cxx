#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define LIM 100008

int a[100008];
int tree[LIM<<2], prefixTree[LIM<<2];

vector<int> all[LIM];
int typeCnt[LIM], tsize;

/* So prefix tree stores largest prefix in it's domain (leftmost point of prefix
 * is leftmost point in it's domain)*/
void update(int ind) {
	int val = tree[ind];
	prefixTree[ind] = val;
	while (ind > 1) {
		ind >>= 1;
		tree[ind] = tree[ind * 2] + tree[ind * 2 + 1];
		prefixTree[ind] = max(prefixTree[ind * 2], prefixTree[ind * 2 + 1] + tree[ind * 2]); 
	}
	return;
}

void printTree(int n) {
	cout << "\n";
	for (int i = 0; i < n; i++) {
		cout << tree[i + tsize] << " ";
	}
	cout << " prefixTree[1]: " << prefixTree[1] << endl;
}
// Still need to check what we actually query...
// int query(int l, int r, int tl, int tr, int ind) {
	// if (l >= tl and r <= tr) {
		// return tree[ind];
	// }
	// int mid = (tr + tl) / 2;
	// int x, y;
	// if (l < mid) {
		// y = query(l, mid, tl, tr, ind * 2);
	// }
	// if (r > mid) {
		// x = query(mid + 1, r, tl, tr, ind * 2 + 1);
	// }
	// return x + y;
// }

int vit[LIM];
void solve() {
	int n, s;
	cin >> n >> s;
	
	// for (auto v : all) {
		// if (!v.empty()) {
			// cout << "VECTR NOT EMPTY BEEP BOOP";
		// }
	// }
	
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
		all[a[i]].push_back(i);
	} // store indexes sorted by trinket type
	
	// Find necessary tree size
	tsize = 1;
	while (tsize < n) {
		tsize <<= 1;
	}
	
	// initialize tree
	for (int i = 0; i < n; i++) {
		int ind = i + tsize;
		if (typeCnt[a[i]] == s) tree[ind] = -s;
		else if (typeCnt[a[i]] > s) tree[ind] = 0;
		else tree[ind] = 1;
		
		typeCnt[a[i]] += 1;
		update(ind);
	}
	// printTree(n);
	
	int ans = prefixTree[1];
	for (int left = 0; left < n; left++) {
		int curType = a[left];
		int ind = left + tsize;
		tree[ind] = 0;
		update(ind);
		if (vit[curType] + s < typeCnt[curType]) {
			int z = all[curType][vit[curType] + s];
			tree[z + tsize] = 1;
			update(z + tsize);
			if (vit[curType] + s + 1 < typeCnt[curType]) {
				z = all[curType][vit[curType] + s + 1];
				tree[z + tsize] = -s;
				update(z + tsize);
			}
		}
		vit[curType] += 1;
		ans = max(ans, prefixTree[1]);
		// printTree(n);
	}
	cout << ans << "\n";
	memset(tree, 0, sizeof(tree));
	memset(prefixTree, 0, sizeof(prefixTree));
	memset(typeCnt, 0 , sizeof(typeCnt));	
	memset(vit, 0, sizeof(vit));
	
	for (int i = 0; i < n; i++) {
		all[a[i]].clear();
	}
	// for (vector<int> &v : all) {
		// v.clear();
	// }
	
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	// ifstream in("LargeTestData.txt");
	// cin.rdbuf(in.rdbuf());
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}

// Iterate from 0, to n - 1, that will be the left end. Then with a given left end,
// query a segment tree from that left point to n - 1, to find the max possible segment.
/* Is this possible? Well to build the second segment tree of max segments in a given range, I think you need
 * to query the first segment tree, not even. It's not possible... So instead the second tree holds the maximum
 * prefix sum in it's range. We can keep the node 1 as the root, despite moving the leftmost point by setting 
 * the old leftmost point as a value of 0 as we go. */

/* A MISTAKE PATTERN THAT I AM MAKING: I am often using += when updating values iteratively when that won't work,
 * i.e.: the value at the current node is supposed to be a sum or something, but previous values could decrease from
 * postive to less positive, and thus should reduce sum, but += doesn't reflect that behavior.
 * 
 * Well, we got past the sample input. Let's see if this works.
 * 
 * OK, so we got WA on the first test set, kind of expected haha. IDK where error is but we'll find it, (I think).
 * 
 * So for individual cases this matches the solution, but with multiple test cases, an answer will change, what isn't
 * being reset properly?
 * 
 * OKAY FOLKS LOOKS LIKE WE FIXED IT! Lesson for today: Range based loops (for auto a : array) by default return 
 * copies of the values!!!! CANNOT STRESS THIS ENOUGH. If you wan't to modify the original object, (aka pass by reference)
 * you use this notation "for (auto &x : array)", i.e.: how you'd do it for a function, you can do with other modifiers like
 * const (and I'm assuming pointers too). So tested pointers, and it doesn't work because it doesn't make sense. If you wanted
 * pointers the array you're accessing would have to be an array of pointers (memory addresses) lol. ANYWAYS, huge thing to learn.
 * 
 * So got past first testset, now runtime error. With LargeTestData set, when all trinkets should be taken, something is going wrong.
 * I changed ints to long long, but then we got like a bajillion, meaning somewhere an unititialized value is being used, or there is 
 * overflow.
 * 
 * OKAY, WAIT, WHAT THE ACTUAL F. I originally had prefixTree[LIM*2], and I thought, hey, maybe let's change that to prefixTree[LIM<<2] even
 * though functionally those should be the same right? WRONG. It now gets the right answer on larger test cases. ?????? I will look at this later.
 * 
 * SO I submitted again, got RE again. I'm like there's no way it's this right? I change tree[200016] to tree[LIM<<2] GUESS WHAT, ANOTHER TEST CASE
 * THAT THE SOLUTION DIDN"T PASS PASSES NOW. WTH???!?!??!*/
