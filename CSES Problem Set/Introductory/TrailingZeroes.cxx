#include <bits/stdc++.h>
using namespace std;

//this naive approach with multiplication and division has time complexity of n*log(n) I think (also not accounting for inefficiency of large number multiplication)
//the correct solution is to count how many factors of 5 there will be (as there will always be more than enough 2s).

int main()
{
	long long n;
	cin >> n;
	//long long b = 1;
	long long cnt = 0;
	for (int i = 5; n / i >= 1; i*= 5) {
		cnt += n / i;
		//while (b % 10 == 0) { naive approach
			//b /= 10;
			//cnt += 1;
		//}
	}
	cout << cnt;
	return 0;
}

