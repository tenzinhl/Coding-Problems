#include <bits/stdc++.h>
using namespace std;
#define ll long long

set<ll> uniqueNumbers;

string filepath = "output.txt";
default_random_engine generator;
int main()
{
	ofstream myfile(filepath, ios::trunc);
	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
	generator.seed(seed);
	uniform_int_distribution<long long unsigned> distribution(0,0xFFFFFFFFFFFFFFFF);
	
	long long n, lb, ub;
	bool unique;
	cout << "Input format: Number of Numbers >> Lower Bound >> Upper Bound >> Unique (1 or 0);\n";
	cin >> n >> lb >> ub >> unique;
	
	if (unique == true) {
		ll cur = distribution(generator) % (ub - lb + 1) + lb;
		for (int i = 0; i < n; i++) {
			while (uniqueNumbers.count(cur) > 0) {
				cur = distribution(generator) % (ub - lb + 1) + lb;
			}
			uniqueNumbers.insert(cur);
			myfile << cur << ' ';
		}
	} else {
		for (int i = 0; i < n; i++) {
			myfile << distribution(generator) % (ub - lb + 1) + lb << " ";
		};
	}
	
	myfile.close();
	return 0;
}

