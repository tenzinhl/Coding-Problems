#include <bits/stdc++.h>
using namespace std;

//Current: So I want to use DFS, and I want to do it iteratively. To do this
//similar to BFS in the parcels problem, you use an array to keep track of visited
//nodes. I also
//want to (and think I successfully have) implement a data structure that
//stores a tree and at the same time keeps track of what character I'm using.
//I think I accomplished this through the "key" system. 

//update: July 4th, much later. But I think it would be interesting to try
//and implement STL data structures on my own while working on problems.
//It will help me understand how these structures can be made (I like how
//in c++ everything is made from the basics), and fully amaze me at how smart
//others are and serve as a constant reminder of how everything you want to do
//can be done, and hopefully improve my ability to implement what I imagine. To
//improve my ability to think programatically.

/* July 9th, we back, we stronger than ever, also screw iterative. Apparently
 * in this case it's barely more space efficient and computationally they're
 * equivalent. F yeah, I think I've almost done it.
 * 
 * So I was looking at other people's submissions. Apparently the way to do this
 * was by using the Set container, as it would only store unique permutations AND
 * it would store them in order. Pretty freaking genius. Good to know for the future.
 * Not to discredit my solution though. It looks pretty frikking smart.*/

//char lets[9][26]; //tree of depth 9, 26 nodes at each branch for every letter
//letr stores 8 depths, and potentially 8 "available" chars at each depth
int lets[26], letr[8][8], lcnt[8];
//lkey correlates a "key" (an index in the array) to a character value (like 'a')
char lkey[8]; 
long facts[9];

void fact() {
	facts[0] = 1;
	facts[1] = 1;
	for (int i = 2; i <= 8; i++) {
		facts[i] = facts[i-1] * i;
	}
}

int word[8];
int d = 0;
string perm = "";

void dfs() {
	int emptyCount = 0;
	for (int i = 0; i < 8; i++) {
		if (lcnt[i] == 0) {
			emptyCount += 1;
			continue;
		}
		lcnt[i] -= 1;
		word[d++] = i;
		dfs();
		lcnt[i] += 1;
		word[--d] = -1; //0 doesn't work because 0 is also index of earliest letter in lkey. Instead we should change null character to hold value of -1
	}
	
	if (emptyCount == 8) {
		for (int i = 0; i < 8; i++) {
			if (word[i] == -1) {
				continue;
			}
			perm = perm + lkey[word[i]];
		}
		
		cout << perm << "\n";
		perm = "";
	}
}

int main()
{
	fact();
	string s;
	cin >> s;
	for (auto c : s) {  //needs work
		int a = c - 'a';
		lets[a] += 1;
	}
	
	//using m to create a key for a given character. This key will then help you find
	//the count of a letter and the character itself. Genius!
	int m = 0;
	int totalChars = 0;
	
	for (int i = 0; i < 26; i++) {
		if (lets[i] >= 1) {
			lcnt[m] = lets[i];
			lkey[m] = 'a' + i;
			totalChars += lets[i];
			m++; //increment "key" for next user in line haha, like dmv
		}
	}
	
	memset(word, -1, 8 * sizeof(int)); //setting values in word array to hold null values.
	
	long totalPermutations = facts[totalChars];
	
	for (int c : lcnt) {
		totalPermutations /= facts[c];
	}
	
	cout << totalPermutations << "\n";
	dfs();
	
	return 0;
}

//this could be a perfect example of when to use recursion. You make a string,
//and each depth of the recursive function you add one of the three characters,
//until none are left.

//PogChamp, we've done it boys.
