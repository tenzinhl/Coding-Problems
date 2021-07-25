#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N_SIZE 1'000'000
string OUTPUT_FILE = "output.txt";
string INPUT_FILE = "running_on_fumes_chapter_1_input.txt";
ofstream stout;
ifstream stin;

	/* So here I'm thinking naive approach is for every node, iterate from 1 to m
	 * nodes away and update the cheapest price of reaching that node (and then presumably
	 * refilling there). However, this would lead to O(N * M), and since N and M can be
	 * as large as 10^6, this is unfeasible. So we need a better solution.
	 * 
	 * Aww man... Directed Acyclic Graphs (DAGs) and shortest path algorithm for it
	 * on geeksforgeeks looked promising, but still has O(V + E) complexity, and for
	 * this problem number of edges (E) = N*M (pretty much). 
	 * 
	 * Okay, idea: so is this crazy? A priority queue or heap that will give us lowest value
	 * in constant time, a queue or container of some sort that let's us know when to remove
	 * elements from that heap. Then we just iterate forwards updating every node with the cheapest
	 * way to gethe there. 
	 * 
	 * Keyword: Sliding Window Maximum (or minimum). I am fairly certain this technique
	 * will help here.*/

int cost[N_SIZE];
ll arrivalCost[N_SIZE], departureCost[N_SIZE]; // departureCost may be redundant, as it's always equal to arrivalCost + cost
deque<int> q; // stores indexes
void solve() {
	int n, m;
	stin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		stin >> cost[i];
	}
	
	// is deque even necessary? We only need to store the minimum for the window right (which would be one variable)?
	// We do. So that e.g.: 1 2 3 4 5 if our window size is 3, eventually 1 will pass out of frame, and then we would need to iterate
	// back to find the current min should be 2, and the point of the queue is it maintains the order of indexes, i.e. : we know left-most
	// must have lowest index, and only worry about checking that one for deletion (due to passing out of frame).
	for (int i = 0; i <= m; i++) {
		arrivalCost[i] = 0;
		departureCost[i] = cost[i];
		if (cost[i] == 0) { // if there is no gas station do not modify deque
			continue;
		}
		
		while (!q.empty() and departureCost[q.back()] > departureCost[i]) {
			q.pop_back();
		}
		
		q.push_back(i);
	}
	
	for (int i = m + 1; i < n; i++) {
		if (!q.empty() and q.front() < i - m) {
			q.pop_front();
		}
		
		if (q.empty()) { // at this point if deque is empty, it means no gas stations within reach of current index and delivery is impossible
			stout << -1 << "\n";
			return;
		}
		
		arrivalCost[i] = departureCost[q.front()];
		
		if (cost[i] == 0) {
			departureCost[i] = 0;
			continue;
		} else {
			departureCost[i] = arrivalCost[i] + cost[i];
		}
		
		while (!q.empty() and departureCost[q.back()] > departureCost[i]) {
			q.pop_back();
		}
		q.push_back(i);
		// cout << "cycle: " << i << "\n";
		// cout << "Front: " << q.front() << ' ' << "Back: " << q.back() << endl;
	}

	stout << arrivalCost[n - 1] << "\n";
	

	q.clear(); // WHY IN THE ACTUAL FUCK DOES THE PROGRAM NOT WORK AS SOON AS I ADD THIS LINE.
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	stin.tie(0);
	stout.open(OUTPUT_FILE);
	stin.open(INPUT_FILE);

	int t;
	stin >> t;
	for (int i = 1; i <= t; i++) {
		stout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}

