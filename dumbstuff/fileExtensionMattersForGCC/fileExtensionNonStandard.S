#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9

// Yup, trying to compile this with the ".lol" extension leads to:
// `fileExtensionNonStandard.lol: file not recognized: File 
// format not recognized` from g++.

/**
 * And if I name it to a known but incorrect extension? (like .S)
 * Fails at the include directive: "No such file or directory"
 */
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}

