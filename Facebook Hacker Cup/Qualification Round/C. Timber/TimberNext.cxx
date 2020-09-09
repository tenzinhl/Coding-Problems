#include <bits/stdc++.h>
using namespace std;
#define ll long long

string OUTPUT_FILE = "output.txt";
string INPUT_FILE = "input.txt";
ofstream stout;
ifstream stin;

map <long, long> mp; // Maps position to key
long m = 1; // global key assignment variable
long left[1600001]; // Stores max length of combined timber interval of which this is the right-most point
long right[1600001]; // Same as left, but this marks the left-most point; (So timber interval is to the right of this point);

// For map oob, could use set to check
long pos[800000], height[800000];

void parseInput(long &n) {	
	for (int i = 0; i < n; i++) {
		stin >> pos[i] >> height[i];
	} 
}

// Returns a key (for accessing left and right arrays) corresponding to a given position, and creates
// new key and updates map for new position.
long getKey(long position) {
	if (mp[position] == 0) {
		mp[position] = m;
		m++;
	}
	
	return mp[position];
}

void placeTree(long &i) {
	long treePos = pos[i];
	long treeHeight = height[i];
	long lkey, mkey, rkey;
	
	mkey = getKey(treePos);
	
}

void solve() {
	long n;
	stin >> n;
	
	parseInput(n);
	for (int i = 0; i < n; i++) {
		placeTree(i);
	}
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

/* OK, SO idea for new solution. Set of positions, map that maps positions to height
 * (as well as normal arrays of positions and heights for iteration).
 * Populate set and map, iterate through data set three times checking for all right-falling
 * solution, left-falling, and >><<. Trouble currently is keeping track of combined intervals.
 * 
 * So I'm thinking original solution actually might still work as long as we add some extra updates.
 * i.e. when falling right if right[mp[pos[i] + height[i]]] exists (is > 0, let's say it's x) then we go to 
 * left[mp[pos[i] + height[i] + x] and update it (add height[i]). This might work? */
