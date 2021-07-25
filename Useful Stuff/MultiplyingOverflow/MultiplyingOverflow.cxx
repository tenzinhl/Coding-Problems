#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9

int main()
{
	int a = INF;
	int b = INF;
	ll c = ((ll)a * b + (ll)a * b) % (int)(1e9 + 7); // For multiplication type casting only applies to the next immediate operation
	cout << c << endl;
	ll d = (a + (ll)b + a + b); // Can typecast either first or second variable in first operation. Result is then long long, which will carry on through implicit typecasting in each following operation.
	cout << d << endl;
	int x = (int) 1e6;
	ll z = (ll)x * (x * x); // Yes, so it applies to all of same priority... NVM
	cout << z << endl;
	
	int y = (int) 1e9;
	ll e = (x * (ll)x * x) + ((ll)y * y);
	cout << "Multiplication separated by addition: " << e << endl;
	// For correct answer here, both expressions must have at least one of the variables involved in the first multiplication
	// to be type-cast to long long (within parantheses). If outside parantheses, result overflows, AND THEN is typecast,
	// which is useless lol.
	return 0;
}

/* How the ordering actually works. When you type-cast, you only type case one variable,
 * or the result of whatever expression is immediate. Then, as the processor computes
 * each operation, it will dynamically cast the result if need be. i.e.: a long long
 * time an int, will automatically make space for a long long. So, that's why with
 * variable z above, placing parantheses will cause overflow, while removing them will
 * give the correct answer (as that way the results are dynamically cast each time they
 * are calculated, but with parantheses the (x*x) will result in type int, which overflows).*/
