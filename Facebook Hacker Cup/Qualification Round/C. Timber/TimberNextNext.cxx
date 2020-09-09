#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N_SIZE 800000

// const string OUTPUT_FILE = "output.txt";
// const string INPUT_FILE = "input.txt";
ofstream stout;
ifstream stin;
// maxLeftLen (and Right): index marks root of leftmost tree and value is total length of longest combined timber interval which that tree is a part of.
long pos[N_SIZE], height[N_SIZE], maxLeftLen[N_SIZE], maxRightLen[N_SIZE], leftEnd[N_SIZE], rightEnd[N_SIZE];
unordered_map<long, long> positions; // converts positions to index in [N_SIZE]
unordered_map<long, long> maxLeftBranch; // leftEndPositions should store the maxLeftLen that ends at that position.
pair<long, long> *trees;

void solve() {
	long n;
	stin >> n;
	
	// sort positions and height together by making pair.
	trees = new pair<long, long> [N_SIZE];
	long tpos, theight;
	for (int i = 0; i < n; i++) {
		stin >> tpos >> theight;
		trees[i] = make_pair(tpos, theight);
	}
	sort(trees, trees + n);
	
	// unpack pairs into respective arrays and deallocate memory for array of pairs
	for (int i = 0; i < n; i++) {
		pos[i] = trees[i].first;
		positions[pos[i]] = i;
		height[i] = trees[i].second;
		leftEnd[i] = pos[i] - height[i];
		rightEnd[i] = pos[i] + height[i];
	}
	delete [] trees;
	trees = NULL;
	
	long leftHighscore, rightHighscore, midHighscore; // forgot to initialize all of these to 0, jeezus.
	leftHighscore = 0;
	rightHighscore = 0;
	midHighscore = 0;
	// Trying trees all tilted left
	for (int i = n - 1; i >= 0; i--) {
		maxLeftLen[i] += height[i];
		if (positions.count(pos[i] - height[i]) > 0) {
			maxLeftLen[positions[pos[i] - height[i]]] = max(maxLeftLen[i], maxLeftLen[positions[pos[i] - height[i]]]); // Error probably here.
		}
		maxLeftBranch[pos[i] - height[i]] = max(maxLeftLen[i], maxLeftBranch[pos[i] - height[i]]); // either a timber interval ending at the point is longer or doesn't exist. We want the max.
		leftHighscore = max(maxLeftLen[i], leftHighscore);
	}
	// All trees tilted right
	for (int i = 0; i < n; i++) {
		maxRightLen[i] += height[i];
		if (positions.count(pos[i] + height[i]) > 0) {
			maxRightLen[positions[pos[i] + height[i]]] = max(maxRightLen[i], maxRightLen[positions[pos[i] + height[i]]]); 
		}
		rightHighscore = max(maxRightLen[i], rightHighscore);
	}
	
	// Trees tilted inwards
	for (int i = 0; i < n; i++) {
		if (maxLeftBranch.count(pos[i] + height[i]) > 0) {
			midHighscore = max(maxRightLen[i] + maxLeftBranch[pos[i] + height[i]], midHighscore);
		}
	}
	
	long ans = max(leftHighscore, max(rightHighscore, midHighscore));
	stout << ans << "\n";

	memset(maxLeftLen, 0, sizeof(long) * N_SIZE);
	memset(maxRightLen, 0, sizeof(long) * N_SIZE);
	positions.clear();
	maxLeftBranch.clear();
}

int main()
{
	time_t start, end;
	start = clock();
	ios_base::sync_with_stdio(false);
	stout.open("output.txt");
	stin.open("timber_input.txt");
	
	int t;
	stin >> t;
	for (int i = 1; i <= t; i++) {
		stout << "Case #" << i << ": ";
		solve();
	}
	end = clock();
	double timeTaken = double(end - start) / double(CLOCKS_PER_SEC);
	cout << "time taken by program is: " << fixed << timeTaken << setprecision(3);
	cout << " sec \n";
	return 0;
}

// HOLY SHIT, HOLY SHIT. IT'S WORKING!!! AAAAAHHHHHHHH!!! WHAT A THRILLLL~ Hopefully timecomplexity is what I predicted
// Okay, so it's failing the validation test data... Sad.

// SAVE THIS TESTCASE IT DIDNT WORK. Returns 17, instead of 18.
// 1
// 16
// 0 1
// 1 1
// 2 1
// 3 1
// 4 1
// 5 1
// 6 1
// 7 1
// 8 1
// 9 1
// 10 1
// 11 1
// 12 1
// 13 1
// 14 1
// 17 2
// 18 3
// nvm... n was wrong in this case... sad.

/* ACTUALLY FRIKKIN FOUND IT: 
1
20
0 1
1 1
2 1
3 1
4 1
5 1
6 1
7 1
8 1
9 1
10 1
11 1
12 1
13 1
14 1
17 2
18 3
19 7
* It returns 36!!! */
