#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9

/* Currently something is wrong with the bound logic, and I'm also confused
 * on the indexing for the positions when doing the rotational math, so I'm gonna
 * start fresh in a new document.*/
std::vector<std::vector<int>> rotateImage(std::vector<std::vector<int>> a) {
	int maxSize = a.size();
	int maxSize1 = maxSize - 1;
	int curRing = 0;
	int s1, s2, s3, s4, y;
	for (curRing = 0; curRing <= (maxSize - 1) / 2; curRing++) {
		for (int x = curRing; x < (maxSize - curRing); x++) {
			y = curRing;
			s1 = a[y][x];
			s2 = a[x][maxSize1 - x];
			s3 = a[maxSize1 - y][maxSize1 - x];
			s4 = a[maxSize1 - x][y];
			a[y][x] = s4;
			a[x][maxSize1 - x] = s1;
			a[maxSize1 -y][maxSize1 - x] = s2;
			a[maxSize1 - x][y] = s3;
		}
	}
	return a;
}

int main()
{

	return 0;
}

