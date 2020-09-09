#include <bits/stdc++.h>
using namespace std;
#define ll long long

string OUTPUT_FILE = "output.txt";
string INPUT_FILE = "input.txt";
ofstream stout;
ifstream stin;

// So we have a dynamically allocated container of some sort, stores a key value
// pair. The key is a given position, and the value stores the max-length chain that ends
// at that point from the left, and the max-length chain that ends at that point from the right.

// We only have N = 800,000, so O(Nlog(N)) should be doable, in other words don't worry about
// the time complexity of insertion or retrieval from a balanced binary tree.

map <long, long> mp; // Maps position to key
long m = 1; // global key assignment variable
long left[1600001]; // Stores max length of combined timber interval of which this is the right-most point
long right[1600001]; // Same as left, but this marks the left-most point; (So timber interval is to the right of this point);

// to solve issue of map creating new element when accessing oob key, we could use a set instead
// to check if we had made a node for a given position...
long pos[800000], height[800000];
void solve() {
	long n;
	stin >> n;
	
	for (int i = 0; i < n; i++) {
		stin >> pos[i] >> height[i];
	}
	
	long curkey, curpos, preleft, preright;
	for (int i = 0; i< n; i++) {
		preleft = left[mp[position[i]]];
		preright = right[mp[position[i]]];
		
		// Handling tree falling left;
		curpos = pos[i] - height[i];
		if (mp[curpos] == 0) {
			mp[curpos] = m;
			m++;
		}
		
		curkey = mp[curpos];
		if (height[i] + right[mp[pos[i]] > right[curkey]) {
			right[curkey] = height[i] + right[mp[pos[i]]];
			left[mp[pos[i] - height + right[curkey]]] = max(
		}
		// right[curkey] = max(height[i] + right[mp[pos[i]], right[curkey]); // so this doesn't work because it will double count a tree...
		
		if (mp[pos[i] + height[i]] == 0) {
			mp[pos[i] + height[i] = m;
			m++;
		}
		
		curkey = mp[pos[i] + height[i]];
		left[curkey] = max(height[i] + left[mp[pos[i]]], left[curkey]);
		
		if (mp[pos[i]] == 0) {
			mp[pos[i]] = m;
			m++;
		}
		/* possibilities for left of current position:
		 * -this tree falls left, and it connects to other timber line, at position pos - height 
		 * -there is already a timber line that ends here
		 * -This tree falls left, and it is the longest/only timber line to end at this point*/
		curkey = m;
		left[curkey] = max(height[i] + left[mp[pos[i] - height[i]]], left[curkey]); // if map[pos[i] - height[i]] doesn't exist it will return 0, left[0] = 0 since global array, so this will work out.
		right[curkey] = max(height[i] + right[mp[pos[i] + height[i]]], right[curkey]);
	}
	
	/* So currently I'm worried about how left and right get updated when a tree falls. If a tree
	 * on the left falls right into a combined timber interval, the right most one won't have it's
	 * left[] get updated. Can we run a cleanup function at the end?*/
	
	m = 1; // reset global key assignment
	memset(left, 0, sizeof(long) * 1600001);
	memset(right, 0, sizeof(long) * 1600001);
}

void MapNode(long position) {
	if (mp[position] == 0)
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

/* Potentially useful notes:
 * 	For any combined timber interval, it's either all left falling, all right falling, 
 *  or (from left to right) all right falling and then all left falling (as all trees have
 *  unique positions and this is the only way to have no holes.
 * 	
 * GASP, after populating the position and height arrays, we can then iterate through the data
 * three times, trying once all left falling, once all right falling, and once >><<< pointing.
 * For the >><< case you switch the directions of trees as you go. I have to figure out the logic
 * to check if it forms a combined timber interval though.*/
