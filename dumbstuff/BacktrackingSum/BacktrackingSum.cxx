#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9

// vector<int> numbers{-8, 2, 12, 15, 21, 23, 27, 34, 42};
// void solve(int use, set<int>used, int sum = 0) {
	// used.insert(use);
	// if (used.size() == numbers.size() && sum == 0) {
		// for (int thing : used) {
			// cout << thing << ' ';
		// }
		// cout << endl;
		// return;
	// }
	// for (int i = 0; i < numbers.size(); i++) {
		// if (used.count(numbers[i])) {
			// continue;
		// }
		// solve(numbers[i], used, sum + numbers[i]);
	// }
// }

bool used[20] = {false};
int numbers[20] = {-8, 2, 12, 15, 21, 23, 27, 34, 42};

void rec(int sum = 0, int index = 0) {
	if (index == 9) {
		if (sum == 0) {
			for (int i = 0; i < 9; i++) {
				if (used[i]) {
					cout << numbers[i] << " ";
				}
			}
			cout << endl;
		}
		return;
	}
	used[index] = true;
	rec(sum + numbers[index], index + 1);
	used[index] = false;
	rec(sum - numbers[index], index + 1);
}
int main()
{
	rec();
	return 0;
}

