#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9

bool isCryptSolution(std::vector<std::string> crypt, std::vector<std::vector<char>> solution) {
	std::unordered_map<char, char> dict;
	for (int i = 0; i < solution.size(); i++) {
		dict[solution[i][0]] = solution[i][1];
	}
	long long nums[3];
	std::string numEquivalent;
	std::stringstream ss;
	char digit;
	for (int i = 0; i < 3; i++) {
		numEquivalent.clear();
		for (int j = 0; j < crypt[i].size(); j++) {
			digit = dict[crypt[i][j]];
			numEquivalent.push_back(digit);
		}
        cout << "i: " << i << " " << numEquivalent << endl;
		// ss.str(numEquivalent);
		// ss >> nums[i];
        if (numEquivalent[0] == '0' and numEquivalent.size() > 1) {
            return false;
        }
        nums[i] = std::stoll(numEquivalent); // key here was to use string to long long.
	}
    cout << nums[0] << " " << nums[1] << " " << nums[2];
	if (nums[0] + nums[1] == nums[2]) {
		return true;
	}
	return false;
}

int main()
{
	return 0;
}

