#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9

// template <typename T>
// class myFunctorionTaker
// {
// public:
	// myFunctorionTaker()
	// {
		// cout << "Function returned: " << T() << endl;
	// }
// };

// bool myBoolFunction()
// {
	// return true;
// }

// class myFalseFunctor
// {
// public:
	// bool operator ()()
	// {
		// return false;
	// }
// };

class myComparisonFunctor
{
public:
	bool operator()(int a, int b) const {
		return a < b;
	}
};

bool myComparisonFunction(int a, int b) {
	return a < b;
}

int main()
{
	// myFunctorionTaker<myBoolFunction> a;
	// myFunctorionTaker<myFalseFunctor()> b;
	map<int, int, myComparisonFunctor> a;
	return 0;
}

