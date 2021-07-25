#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAX_ROW 10
#define MAX_COL 10
set<ll> uniqueNumbers[MAX_COL]; // I don't imagine more than 10 columns
set<ll> dummy;

ofstream myfile;
string filepath = "output.txt";

long long rows[MAX_COL], lb[MAX_COL], ub[MAX_COL];
bool unq[MAX_COL];

// random_device rd; This junk kept returning the same number.
default_random_engine generator;

void generateNumber(ll &lb1, ll &ub1, uniform_int_distribution<long long unsigned> &distribution, bool uniq = false, set<ll> &numSet = dummy) {
	if (uniq == true) {
		ll cur = distribution(generator) % (ub1 - lb1 + 1) + lb1;
		while (numSet.count(cur) > 0) {
			cur = distribution(generator) % (ub1 - lb1 + 1) + lb1;
		}
		numSet.insert(cur);
		myfile << cur << ' ';
	} else {
		myfile << distribution(generator) % (ub1 - lb1 + 1) + lb1 << " ";
	}
}

int main()
{
	myfile.open(filepath);
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	generator.seed(seed);
	uniform_int_distribution<long long unsigned> d1(0, 0xFFFFFFFFFFFFFFFF);
	
	long long row, col;
	cout << "Input: No. of Columns >> No. of Rows;\n(For each column): \nLower Bound >> Upper Bound >> Unique? (optional, 1 or 0, (not optional yet));\n";
	cin >> col >> row;
	for (int i = 0; i < col; i++) {
		cin >> lb[i] >> ub[i] >> unq[i];
	}
	
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			generateNumber(lb[j], ub[j], d1, unq[j], uniqueNumbers[j]);
		}
		myfile << "\n";
	}
	myfile.close();
	return 0;
}
/* Generate for Energy Stones
3 4
1 1 0
1 20 0
0 20 0 
* */
