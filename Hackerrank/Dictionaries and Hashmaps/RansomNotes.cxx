#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9
unordered_map<string, int> dict;
void checkMagazine(vector<string> magazine, vector<string> note) {
	string word;
	for (int i = 0; i < magazine.size(); i++) {
		word = magazine[i];
		if (!dict.count(word)) {
			dict[word] = 1;
		} else {
			dict[word] += 1;
		}
	}
	
	for (int i = 0; i < note.size(); i++) {
		word = note[i];
		if (!dict.count(word)) {
			cout << "No" << endl;
			return;
		}
		if (dict[word] == 0) {
			cout << "No" << endl;
			return;
		}
		dict[word] -= 1;
	}
	
	cout << "Yes" << endl;
	return;
}

int main()
{
	return 0;
}

