#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9
const int LIM = (int) 1e7 + 8;
ll tree[LIM * 4];
int tsize;
vector<vector<int>> qs;

// Update all nodes top level nodes that represent the given segment, by adding the given val to all those nodes.
void updateTree(int b, int e, int val, int l = 0, int r = tsize - 1, int ind = 1) {
	if (l >= b and r <= e) {
		tree[ind] += val;
		return;
	}
	int mid = (l + r) / 2; // Left leaning
	// cout << l << " " << r << " ind: " << ind << " b&e: " << b << " " << e << endl;
	if (b <= mid) {
		updateTree(b, e, val, l, mid, ind * 2);
	}
	if (e > mid) {
		updateTree(b, e, val, mid + 1, r, ind * 2 + 1);
	}
	return;
}

// Given a leaf, find the value of summing all nodes along its branch to the root.
ll checkVal(int i) {
	int ind = tsize + i;
	ll ans = 0;
	while (ind >= 1) {
		ans += tree[ind];
		ind >>= 1; // divide by 2
	}
	return ans;
}

long arrayManipulation(int n, vector<vector<int>> queries) {
	tsize = 1;
	while (tsize < n) {
		tsize <<= 1;
	}
	
	int a, b, k;
	for (auto &query : queries) {
		a = query[0] - 1;
		b = query[1] - 1;
		k = query[2];
		updateTree(a, b, k);
	}
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ans = max(checkVal(i), ans);
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<int> query_temp;
	int val_temp;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> val_temp;
			query_temp.push_back(val_temp);
		}
		qs.push_back(query_temp);
		query_temp.clear();
	}
	
	cout << arrayManipulation(n, qs);
	return 0;
}

/* OKAY, so I think I have it. It's like a segment tree, for each query you update
 * the necessary nodes and add the value of the operation to each node. Do this
 * for each query in O(M * log(N)). Then we iterate through every leaf, going up its
 * corresponding branch all the way to the root, adding the value of every node
 * along the branch. This can be done in O(N * log(N)). Asymptotically this becomes
 * O(N * log(N)). I'm not too sure if that's good enough for 10 ^ 7 numbers though...
 * But I find it hard to believe you can do better than (N * log(N)), I guess (M * log(N))
 * is better... but idk if that's possible. I hope it's fine since log_2(1e9) is only
 * 30.*/

// Always be careful with +='s.

/* LOL, in updateTree() I moved val to be the third argument (so it would be ahead of
 * the default arguements as C++ requires), but I didn't change the order of the arguements
 * I was passing to the recursive function inside lol!.
 * 
 * AHH! So then I got the stack overflow error code, and after some digging found that
 * it's because I FORGOT THEY PASS THEIR LEFT AND RIGHT as 1-based indexes, where my
 * function needs 0-based indices. I thought about this at the beginning but forgot lol.
 * 
 * // GAWWWDDD IM SO DUMB. Quite a few errors have been found since, for 1, I had b, e
 * and l, r backwards in my logic for updating the segment tree (should update if l and r
 * are within b and e, not the other way around), next, I told myself that I need to clear
 * the temp_vector after each push to the main outside vector, BUT IWASNT DOING THAT, AND THAT
 * EXPLAINS WHY B E AND K WERE ALL THE SAME EVERY TIME GASH.
 * 
 * WAAIITTT, I think I had my b, e, l, r logic right the first time, but I thought it was the error
 * when it wasn't. think I had it right originally?*/

/* LET'S FRIKKIN GOOOOOO. WE GOT IT. IM HUGEST OF BRAINS.*/

/* It's interesting, reflecting on this problem I've come to realize it's like most segment tree
 * problems except the logic of updating and querying are opposite. Normally when you update
 * you go from a leaf to the root, whereas here you go the the nodes that contain a range and
 * update them (which is how you'd normally query). Interesting stuff.*/
