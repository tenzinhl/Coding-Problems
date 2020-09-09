#include <bits/stdc++.h>
using namespace std;

//new attempt, figured out the math on paper. Proud of myself. Checked on
//Desmos and the formula works.
int main()
{
	int n;
	cin >> n;
	//can't precompute lol because you have to use the incrementing i.
	//long long n2 = n * n;
	//long long n3 = 
	//long long n4 = n2 * n2;
	
	long long i2, i4;
	for (long long i = 1; i <= n; i++) {
		i2 = i * i;
		i4 = i2 * i2;
		
		//cout << i4 << "\n";
		cout << ((i4 - i2) / 2) - (4 * (i2 - 3 * i + 2)) << "\n";
	}
	
	return 0;
}
