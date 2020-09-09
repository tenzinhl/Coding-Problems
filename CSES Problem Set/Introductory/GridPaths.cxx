#include <bits/stdc++.h>
using namespace std;
#define ll long long

/* trie specifications: 4^48. Number is way too huge... I don't think trie will work.
 * How about as we search for paths with our backtracking, we only search for paths
 * that match description?. Wait, I just realized 4^48 represents all possibilities 
 * in an open 2D space, not in this grid. With proper pruning, we can probably
 * fit this into a trie still. For starters, at any given node there are only at most
 * 3 valid choices for movement (since you can't go back), and for many nodes there
 * will only be 2 or 1. PLUS (how did I NOT THINK OF THIS), The trie only needs to hold
 * valid solutions (DUMBASS!), and since we know there are only 88418 solutions, we EASILY
 * have enough memory for that.*/

long trie[4000000][4], cnt[100000];
//finally gonna use map to map char to direction lol; I was trying to be fancy by making these const, but apparently then you can't access the members, so F me.
map<char, int> ctoint = {
	{'D', 0},
	{'U', 1},
	{'L', 2},
	{'R', 3},
};

map<int, char> inttoc = {
	{0, 'D'},
	{1, 'U'},
	{2, 'L'},
	{3, 'R'},
};

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

/* July 14th, okay. Grid paths. The first thing we want to do is build a
 * trie of all valid paths (pretty sure at least). I think this can only be done through backtracking. 
 * We can optimize the backtracking by cutting off some branches.
 * Optimizations:
 * 	-{Since every solution will have a mirror version that is correct, we
 * 	 can start every solution (nvm, since solution must end in bottom left corner)}
 * 	-If one of adjacent squares is edge, and other 2 adjacent squares are both open
 * 	 we know solution is invalid
 * 
 * Actually, before we plan out this backtracking algorithm, is a trie what we want?
 * I was thinking every node will have the number of strings that include that prefix.
 * Then you iterate through entire tree (recursively probably) and when
 * you hit defined depth (where char isn't '?') then you subtract all branches
 * that aren't the required character from total number of solutions(and
 * you don't continue to iterate through those branches). Yeah... that 
 * should work(?)*/
 
bool board[7][7]; //origin square in board is occupied (update: but based on how function is written, origin square should be false //squares numbered left to right, top to bottom
//int ds[4] = {7, -7, -1, 1}  //down, up, left, right

long m; //it's funny how as ideas develop and change I have leftover variables for ideas that didn't come to be, and now I have deleted them as they throw compiler errors.
string path;

//vector <long> nodesByDepth[49]; //hold up, this idea still doesn't help because eventually we need subsets of nodes, and this array doesn't tell us about that. Old idea
long pb;
void updateTrie() {
	pb += 1;
	// cout << path << "\n";
	long u = 0;
	long node;
	long depth = 0;
	for (char c : path) {
		node = trie[u][c - '0'];
		if (!node) {
			node = ++m;
		}
		cnt[node] += 1;
		u = node;
		depth += 1;
		// cout << m << "\n";
	}
	// J. 17, so currently hitting 2086 solutions before I get the 1078169 or whatever error code (it means I'm writing to memory reserved for the OS, i.e.: I'm writing somewhere far beyond where I should)
	// okay, so my math for how large to make trie was off. I was using 88418 correct solutions as my base, but each if each solution had no matching characters
	// then worst case there would be 88418 * 48 (chars per solution) nodes. So I need to expand trie.
}

long step = 0;

// Check if a node is a special case (i.e.: last node or dead end node. Return true if node is special case (special cases always are dead ends)
bool checkNode(int x, int y) {
	
	if (board[x][y] or x < 0 or x >= 7 or y < 0 or y >= 7) { //skip square if out of bounds or already visited
		return true;
	} // weird, so this check doesn't work, and still leads to infinite loop, check before pushing is key. WHY? Shouldn't they be equivalent?
	// July 18, this line is necessary for preventing infinite loop. But I feel like it is slowing program down greatly.
	
	// kind of irrelevant, but removing the above check causes the step to go up WAY FASTER while infinite looping. Are if statements that costly? Or what.

	if (x == 0 and y == 6) { // remember 0 based indexing for coords and step
		if (step == 49) { // okay, so this fixed it, it has to be step 49 for some reason... AH, because we mark the origin as step 1. So now we're updating Trie at least. (Ju 17)
			updateTrie();
		}
		return true;
	}
	
	if ((x == 0 or x == 6) and y > 0 and y < 6) {
		if (!board[x][y-1] and !board[x][y+1]) {
			return true;
		}
	}
	
	if ((y == 0 or y == 6) and x > 0 and x < 6) {
		if (!board[x - 1][y] and !board[x + 1][y]) {
			return true;
		}
	}
	
	return false;
}

void backtracking(int x, int y) {
	step += 1;	
	
	if (checkNode(x, y)) { //if node is dead end, return (stop investigating this branch)
		step -= 1;
		return;
	}
	
	board[x][y] = true;
	int xp, yp;
	char c;
	for (int i = 0; i < 4; i++) { // make a string of 0 - 3's 
		c = '0' + i;
		path.push_back(c); // so apparently string.append() doesn't accept chars. wtf. what about push_back()? YUP. Okay, so now we know a major difference between the two.
		xp = x + dx[i];
		yp = y + dy[i];
		if (xp >= 0 and xp < 7 and yp >= 0 and yp < 7 and !board[xp][yp]) //issue for only step 1 was here. 0 should be included in range. Later: THIS IF HAS NO FRIKKING BRACKETS HOWD I NOT NOTICE THIS WTF
			backtracking(xp, yp);
		path.pop_back();
	}
	// cout << step << " " << x << " " << y << "\n" << path << "\n"; // OOOOHHH I FINALLY SEE IT. I INCREMENT STEP AT THE beginning but in checkNode() I don't decrement in, and that's why it goes to infinity. (July 17)
	
	board[x][y] = false;
	step -= 1;
	return;
}

//queue<long> q; // q of trie nodes. (m keys) //old idea
vector<long> curDepth; // array of trie nodes that correspond to current move depth
vector<long> nextDepth;
long bfs(string target) { // not sure if it's actually bfs, but it seems like it?
	long fin = 88418;
	// long depth; unnecessary now pretty sure
	/* So what I want to do is have an array/vector of all of the nodes
	 * to check for the current depth, and then check them. So I should have two vectors to
	 * solve my current issue of pushing nodes based on current ones, but then clearing them
	 * later. */
	for (ll unsigned int i = 0; i < target.length(); i++) {
		char curChar = target[i];
		curDepth = nextDepth; // yes, apparently vectors can just do this lol
		nextDepth.clear();
		if (curChar == '?') {
			for (long node : curDepth) {
				for (int j = 0; j < 4; j++) { //add next nodes for given node, now we need to do that for every node
					long cur = trie[node][j];
					if (cur == 0) {
						continue;
					} else {
						nextDepth.push_back(cur);
					}
				}
			}
		} else { //as I'm writing this I am realizing this could be refactored to have the if statement deeper in the
			// loop and thus be more concise. But writing it this way is clearer to me as it matches my thought process better
			int d = ctoint[curChar];
			for (long node : curDepth) {
				for (int j = 0; j < 4; j++) {
					if (j != d) {
						fin -= trie[node][j];
					} else {
						nextDepth.push_back(trie[node][j]);
					}
				}
			}
		}
	}
	
	return fin;
}

int main()
{
	backtracking(0, 0); //populate trie with solutions
	/* So... currently backtracking is infinite looping. I remember
	 * something similar happening with bfs() in parcels, where you needed 
	 * two if statements checking for invalid squares, one before pushing, 
	 * and one when actively on it... I still don't get why. Might not be 
	 * an issue actually. Infinite loop fixed, but updateTrie is never being run.
	 * 
	 * Backtracking isn't even going deeper than first step HAHA. How have I goofed so hard.
	 * Fixed issue with validity check, but now it's infinite looping again.*/
	
	cout << "Hi we got here" << pb; //<< "\n" << trie[0][0]; // (July 17, ok so still infinite looping. Gonna add second if statement check back in, and see if it fixes it like bfs.
	string target; // The target string to look for
	cin >> target;
	//long solutions = 88418; // potential solutions that match target string. Outdated and unnecessary now
	// Ah yes, in my pride with completing the 'bfs()' I forgot to finish main() lol.
	long ans = bfs(target);
	cout << ans;
}

// J. 18, besides being a little slow, backtracking is updating trie 88418 times, which is 100% correct. Trie[0][0] = 1 though, which is clearly wrong.
// I wonder if solution can be refactored to try and match target string as it goes, instead of updating a trie and
// then checking the trie at the end. It might be much more efficient...

/* Let's do the maths. If we're loooking at Big-O, our input is basically the side length of the board. I would say at each
 * node we have 2-3 choices of direction on average till we near the end, so it's (2)^n^2 big O. then update trie is path length, which is n^2.*/
