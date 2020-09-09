#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long t, y, x;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> y >> x;
		long long layer;
		layer = max(x,y);
		long long ans;
		long long root = layer * layer;
		if (layer % 2 == 0) {
			ans = root - (x - 1) - (layer - y);
		} else {
			ans = root - (y - 1) - (layer - x);
		}
		
		cout << ans << "\n";
	}
		
	return 0;
}

//if x is odd, (x,1) will be x^2
//if y i even, (1,y) will be y^2
