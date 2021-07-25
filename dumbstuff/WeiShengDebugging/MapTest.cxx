#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9

int main()
{
	map<char, int> myMap;
	myMap['a'] = 1;
	myMap.find('a')->second = myMap.find('a')->second + 1;
	cout << myMap['a'] << endl;
	return 0;
}

