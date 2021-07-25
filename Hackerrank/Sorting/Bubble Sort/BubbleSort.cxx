#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9

void countSwaps(vector<int> a) {
	int swapCnt = 0;
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < a.size() - 1; j++) {
			if (a[j] > a[j+ 1]) {
				swapCnt += 1;
				swap(a[j], a[j+1]);
			}
		}
	}
	
	cout << "Array is sorted in " << swapCnt << " swaps." << endl;
	cout << "First Element: " << a[0] << endl;
	cout << "Last Element: " << a[a.size() - 1] << endl;
	return;
}

int main()
{
	return 0;
}

