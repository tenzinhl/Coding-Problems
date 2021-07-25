#include <bits/stdc++.h>
using namespace std;

//there is probably a way to clean up all of these arrays (combine) by
//making a struct "node" and then making an array of those structures.
//I'm gonna try that.

int r, c;
string offices[250];
int isOffice[250][250];
char checked[250][250];
queue <pair <int,int>> q;

void solve() {
	cin >> r >> c;
	int disd = 0;
	
	for (int j = 0; j < r; j++) {
		cin >> offices[j];
		for (int i = 0; i < c; i++) {
			isOffice[i][j] = (int) offices[j][i];
			if (isOffice[i][j] == 1) {
				q.push(make_pair(i,j));
				disd += 1;
				checked[i][j] = 1;
		}
	}
	
	auto cur = q.front();
	while (disd < tsquares) {
		cur = q.front();
		q.pop();
		
		if (checked[i][j] != 1) {
			disd += 1;
			checked[i][j] = 1;
			
	 
}

int main()
{
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}

