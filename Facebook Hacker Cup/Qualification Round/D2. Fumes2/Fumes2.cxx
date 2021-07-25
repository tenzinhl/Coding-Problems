#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define Fox(i, n) for (i = 0; i < n; i++)

#define N_SIZE 1'000'008
string OUTPUT_FILE = "output.txt";
string INPUT_FILE = "Problem.txt";
ofstream stout;
ifstream stin;

int z = 1;
int parent[N_SIZE], cost[N_SIZE], treeParents[N_SIZE], mZ[N_SIZE], mD;
long long treeSize;
// int mainD; // stores "distance" of which node we are branching off in main path for use in dfs2();
const int INF = (int) 1e9;
int minCost[N_SIZE]; // stores max Cost for a given depth in side branches
vector<int> connections[N_SIZE];
long long tree[2 * N_SIZE + 8];

// Depth first search to find direct path from A to B, and to update distance of all nodes from B. (DFS starts at node B);
// this is causing stack overflow. How to avoid?
void dfs(int node) {
	for(int c : connections[node]) {
		if (c != treeParents[node]) {
			treeParents[c] = node;
			dfs(c);
		}
	}
	return;
}

void dfs2(int previous, int node, int depth, int &m) {
	if (depth >= m) {
		return;
	} // if we are at the fuel tank's max distance within a side-branch, we would need to refuel at the nearest main node anyways, and thus further depth can be ignored.
	for (int c : connections[node]) {
		if (c != treeParents[node] and c != previous) {
			if (mZ[depth + 1] != z) {
				mZ[depth + 1] = z;
				mD = max(mD, depth + 1);
				minCost[depth + 1] = cost[c];
			} else {
				minCost[depth + 1] = min(minCost[depth + 1], cost[c]);
			}
			dfs2(node, c, depth + 1, m);
		}
	}
	return;
}

// Update segment tree (which stores minimum cost of having a full gas tank at a distance (direct distance from a to b) - i from the target node (along the main path since other branches can be ignored))
void update(int distance, long long cst) {
	distance += treeSize;
	while (distance) {
		tree[distance] = min(tree[distance], cst);
		distance >>= 1;
	}
	// Segment tree root node index is 1
	return;
}

// Return minimum value within given segment of array
// start at top of tree. r1 and r2 are the range of curNode in tree, lb and ub are bounds which we are searching.
long long queryTree(int curNode, int r1, int r2, int lb, int ub) {
	if (r1 >= lb and r2 <= ub) {
		return tree[curNode];
	}
	int mid = (r1 + r2) / 2;
	long long ans = (long long) INF * INF;
	if (lb <= mid) {
		ans = min(ans, queryTree(curNode * 2, r1, mid, lb, ub));
	}
	if (ub > mid) {
		ans = min(ans, queryTree(curNode * 2 + 1, mid + 1, r2, lb, ub));
	}
	return ans;
}

void solve() {
	int n, m , a, b;
	stin >> n >> m >> a >> b;
	
	// Store parents and costs from input
	for (int i = 0; i < n; i++) {
		stin >> parent[i] >> cost[i];
		parent[i] -= 1; // convert to 0-based indexing.
		if (cost[i] == 0) {
			cost[i] = INF + 1;
		}
	}
	// hodge podge solution to fact that I missed that problem is based on 1-based indexing.
	a -= 1;
	b -= 1;
	
	// Store which other nodes each node is connected to
	for (int i = 1; i < n; i++) { // we skip index 0 (city 1), as it has no parent
		connections[i].push_back(parent[i]);
		connections[parent[i]].push_back(i);
	}
	
	memset(treeParents, -1, sizeof(treeParents));
	// Set node b as root by indicating no parent (value of -1), then dfs to create new tree.
	treeParents[b] = -1;
	dfs(b);
	treeSize = 1;
	while (treeSize < n) {
		treeSize <<= 1;
	}
	
	memset(tree, 60, sizeof(tree));
	update(0, 0);
	int curNode = treeParents[a];
	int previous = a;
	int k = 1;
	z = 1;
	while (curNode != b) {
		minCost[0] = cost[curNode];
		if (cost[curNode] > INF) {
			mZ[0] = 0;
		} else {
			mZ[0] = z;
		}
		dfs2(previous, curNode, 0, m);
		for (int i = 0; i <= mD; i++) { // HERE IT IS. THIS IS WHY 17 TAKES FOREVER. and that's what the weird dudes mD thing was. Use a variable so as to not M times each time when you don't need to, only iterate as many times as the max depth of branches. Good.
			// here i represents depth of side-branch
			if (k - i >= 0 and mZ[i] == z and minCost[i] <= INF) {
				update(k - i, minCost[i] + queryTree(1, 0, treeSize - 1, max(0, (k + i - m)), k));
			}
		}
		k += 1, z++;
		previous = curNode;
		curNode = treeParents[curNode];
	}
	
	// reset connections
	for (int i = 0; i < n; i++) {
		connections[i].clear();
	}
	
	memset(mZ, 0, sizeof(mZ));
	long long ans = queryTree(1, 0, treeSize - 1, max(0, k - m), k - 1); // IM SO DUMB FUCK! I DECLARED ANS AS AN INT. OF COURSE IF F****ING OVERFLOWS.
	// so we iterate from a to b along the main path, at each node in the main path we DFS outwards up to m - 1 nodes away.
	// At each node we update the segment tree. To find the arrival cost of one of these branch nodes we query the segment
	// tree for the minimum cost of departure for [i - m + d, i]  (where d is the depth of the side branch).If we query and
	// update the tree once for each branch node, we'll have a worst case of O(nlog(n)) I think.
	stout << (ans >= (long long) INF * INF ? -1 : ans) << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	stin.tie(0);
	
	stout.open(OUTPUT_FILE);
	stin.open(INPUT_FILE);
	
	time_t start, end;
	start = clock();
	
	int t;
	stin >> t;
	for (int i = 1; i <= t; i++) {
		stout << "Case #" << i << ": ";
		solve();
	}
	
	end = clock();
	double timeTaken = double(end - start) / double(CLOCKS_PER_SEC);
	cout << "time taken by program is: " << fixed << timeTaken << setprecision(5);
	cout << " sec \n";
	return 0;
}

/* Problems to be solved: 
 *  -Accounting for no-gas station, Done.
 *
 * I'm gonna consider this a success. I should actually be really happy. The implementation is heavy
 * and my program returns correct results for all the test cases I can verify alone. Which is really good!
 * The only issue is that on Windows the stack size is smaller than on linux (and with my current setup
 * I can not easily change the stack size), and to rewrite the program to use an iterative dfs would take some
 * time. I'll probably get on it tomorrow, but I should be, and genuinely do feel, very proud to have successfully
 * implemented the solution to this problem. Perhaps it slightly takes away from it that I looked at the other guys
 * code, but I should realize, it was barely helpful at all. I did real good! */
