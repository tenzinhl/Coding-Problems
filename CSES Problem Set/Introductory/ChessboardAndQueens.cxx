#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool board[8][8]; //row, col. True means obstructed
bool colBlocked[8], rowBlocked[8], slashDiag[15], backslashDiag[15]; //faster way of checking if queen location is valid  
int count;
short queenX[8], short queenY[8]; //store location of queen no. i

int main()
{
	string s;
	for (int i = 0; i < 8; i++) {
		cin >> s;
		for (int j = 0; j < 8; j++) {
			if (s[i] != '.')
				board[i][j] = 1;
		}
	}
	
}

//an array to keep track of what squares each queen has already tried
/* So here's how the algorithm should work:
 * 	-Place a queen on the first possible open square
 * 	-if there are no open squares move the previous queen to it's next possible
 * 	 open square
 * 	-For 8th queen, if successfully placed, increase counter, and try to replace
 * 	-8th queen. (When a solution is reached (aka 8th queen is successfully placed)
 * 	 increase counter, but keep running algorithm.)
 * 	-How to know when to stop algorithm? I guess once queen one reaches square
 * 	 64, which should be max? I'm GENIUS, thought about it, I think it 
 * 	 should be when queen one reaches square 65 (out of bounds), as that
 * 	 represents the program having to backtrack all the way to the first queen
 * 	 when square 64 doesn't work. At which point we should have iterated
 * 	 through all valid positions.
 * 	 -So I snuck a peek at the GeeksforGeeks writeup, apparently you can
 * 	  make it even simpler by knowing each row needs at least one queen
 * 	  and only checking a column for each queen, instead of 64 squares.*/
 
//July 11th (btw) I'm feeling like this another recursive problem... not iterative.
/* So yeah, I looked it up and this is another one of those ones where you would
 * have to implement a LIFO stack structure to make it iterative. And based
 * on what I've read, converting it to iterative doesn't really accomplish much.
 * The main reason to convert to an iterative approach is for better space
 * complexity (using less RAM). But considering the decision tree for this problem
 * only goes at most 8 layers deep (and it barely passes any variables), that is
 * far from a concern. Besides space complexity, I have found nothing online
 * suggesting iteration and recursion differ (such as in speed, or time complexity).
 * I guess they differ in code-length, if that really matters. Recursion is usually
 * easier to read and understand intuitively. */
 
 /*BREAKTHROUGH! Small but important for a different project. When you want to 
  * implement recursive algorithms like these iteratively, use a while loop and
  * not for loops, to check for a condition being satisfied! IT MATCHES the idea
  * of the recursion. Makes sense. Unless it's a DP problem, in which case a for
  * loop through all states/ potential values makes sense. But when it involves layers,
  * while loop and stack data structure. YESSS*/

/* So while thinking about how you would implement dfs iteratively for the 
 * string bundling Kickstart problem, I was getting confused. I looked it up
 * and I was on the right track. When doing dfs iteratively you have
 * one stack that serves the equivalent function of the queue in bfs, but
 * I knew that stack didn't hold the information of the path to your node.
 * So I felt like you would need another data structure. And I WAS RIGHT!
 * You use another stack to keep track of the path to your node. Could use
 * an array too. Wait... I need to get on this at some point. Something still
 * feels off. YESS, ok, you use the post-order traversal stack to then work backwards
 * and process each node. */
 
/* Was gonna scan this "rant" but I'm just gonna type it here instead.
 * (Although wanting to scan it reminded me that I need to install the 
 * Canon drivers on this computer). :
 * 
 * You always need a queue of some sort in iterative approaches to algorithms
 * like these. When you want to navigate a certain way, you need a roadmap,
 * a menu, a "queue". So while we use a "stack" container for dfs(), it
 * really is a way for us to keep track of where to go next, a "queue". This
 * realization is important because for problems like this Queen one, in my
 * head I was imagining keeping track of the path you took to the node you are
 * at, but for us to make a queue the way we want, we cannot preserve that
 * information in the stack container. That is why we will need a second stack
 * for postorder traversal, in order to store that sort of information.
 * 
 * Retrospectively, the second stack is still a sort of queue. I struggled to
 * find this solution of using a second stack (had to look it up), as I was
 * only looking at traversing back up one branch at a time, forgetting it's
 * really more about (in fact necessary) to process deepest then back up.
 * Since our first dfs() traversal guarantees all child nodes will be traversed
 * after parent node, we can reverse that order to get desired postorder
 * traversal behavior. */
 
stack <int> q;
int depth;
void backtracking() { //limit each queen to a column
	
}

void placeQueen(int row, int col) {
	for (int i)
}
