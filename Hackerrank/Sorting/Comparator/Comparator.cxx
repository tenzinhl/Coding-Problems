#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9

struct Player {
	int score;
	string name;
};

class Checker{
public:
	// complete this method
	static int comparator(Player a, Player b)  {
		if (a.score > b.score) {
			return 1;
		} else if (a.score < b.score) {
			return -1;
		} else if (a.score == b.score) {
			if (a.name > b.name) {
				return -1;
			} else if (a.name < b.name) {
				return 1;
			} else if (a.name == b.name) {
				return 0;
			}
		}
	}
};

int main()
{
	return 0;
}

