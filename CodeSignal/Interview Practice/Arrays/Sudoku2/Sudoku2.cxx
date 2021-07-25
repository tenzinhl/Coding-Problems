#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9

unordered_set<char> square[3][3];
unordered_set<char> rows[9];
unordered_set<char> cols[9];
bool sudoku2(std::vector<std::vector<char>> grid) {
	const int n = grid.size();
	char curVal;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			curVal = grid[i][j];
			if (curVal == '.') {
				continue;
			}
			if (rows[j].count(curVal) or cols[i].count(curVal) or square[i/3][j/3].count(curVal)) {
				return false;
			}
			rows[j].insert(curVal);
			cols[i].insert(curVal);
			square[i/3][j/3].insert(curVal);
		}
	}
	return true;
}

int main()
{
	return 0;
}

/* yeah okay this logic worked. I just want to point out that this could say "true"
 * to a technically unsolvable puzzle, since all it checks is if the starting position
 * doesn't contradict itself immediately. For example, have one of the 3X3 grids filled
 * with all but one position (thus forcing that position to hold a value x). If there
 * was already a value x in the same row as that empty square, it would be impossible
 * to solve the puzzle, but this program would still mark that arrangement as "true".
 * So I think that's a pretty bad question, and the specification should have been
 * written better. Anyways, I'm still super drained from that rotation problem.
 * 
 * Time to go next I guess. Sept. 12, 2020 7:42 PM.*/
