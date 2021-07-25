#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main()
{
	istringstream iss;
	string a = "1 2 3 4 5";
	iss.str(a);
	int temp;
	while (!iss.eof()) {
		iss >> temp;
		cout << temp;
	}
	return 0;
}

