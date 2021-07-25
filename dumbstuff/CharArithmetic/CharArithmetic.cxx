#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9


int main()
{
	char a = 'A';
	int curChar = a - 'A';
	curChar -= 1;
	string ans;
	ans.push_back(curChar + 26 + 'A');
	cout << ans;
	return 0;
}

