#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9

// void rotate(int x, int y, std::vector<std::vector<int>>& a) {
	// int s1, s2, s3, s4;
	// s1 = a[y][x];
	// s2 = a[x][n-y];
	// s3 = a[n-y][n-x];
	// s4 = a[n-x][y];
	// a[y][x] = s4;
	// a[x][n-y] = s1;
	// a[n-y][n-x] = s2;
	// a[n-x][y] = s3;
// }
std::vector<std::vector<int>> rotateImage(std::vector<std::vector<int>> a) {
	const int n = a.size();
	int n1 = n - 1;
	for (int ring = 0; ring < n/2; ring++) {
		for (int x = ring; x < n - 1 - ring; x++) {
			int s1, s2, s3, s4;
			int y = ring;
			s1 = a[y][x];
			s2 = a[x][n1-y];
			s3 = a[n1-y][n1-x];
			s4 = a[n1-x][y];
			a[y][x] = s4;
			a[x][n1-y] = s1;
			a[n1-y][n1-x] = s2;
			a[n1-x][y] = s3;
		}
	}
	return a;
}

int main()
{
	return 0;
}

