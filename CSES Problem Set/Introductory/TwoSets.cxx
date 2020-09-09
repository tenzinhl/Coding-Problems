#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long n;
	cin >> n;
	long long rem = (n - 1) % 4;
	if (rem < 2) {
		cout << "NO";
		return 0;
	}
	
	cout << "YES" << "\n";
	
	if (rem == 2) {
		//just build two arrays and output at the end... ehh realized you'll need two if statements anyways...
		//int ara[], arb[];
		//for (int i = 0; i < (n - 3) / 2; i++) {
			
		cout << n / 2 + 1 << "\n" << "1 2";
		for (long i = 0; i < (n - 3) / 2; i+= 2) {
			cout << " " << 4 + i << " " << n - i;
		}
		
		cout << "\n" << n / 2 << "\n" << "3";
		
		for (long i = 0; i < (n - 3) / 2; i+= 2) {
			cout << " " << 5 + i << " " << n - 1 - i ;
		}
	}
	
	if (rem == 3) {
		cout << n / 2 << "\n";
		for (long i = 0; i < n / 2; i += 2) {
			cout << 1 + i << " " << n - i << " ";
		}
		
		cout << "\n" << n / 2 << "\n";
		for (long i = 0; i < n / 2; i += 2) {
			cout << 2 + i << " " << n - 1 - i << " ";
		}
	}
	 
	return 0;
}

