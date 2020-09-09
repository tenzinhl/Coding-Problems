#include <bits/stdc++.h>
using namespace std;
#define ll long long
/* OKAY, July 13th Update: So using some cout statements (and placing queens
 * on a chessboard for like 30 mins on lichess.com to work through it myself lol)
 * I have verified that the logic for blocking squares and placing queens, and incrementing
 * all works great! So the issue must come somewhere from when we place the
 * 7th (8th in normal counting) queen. Somewhere the logic in that if statement
 * is goofing the program. At least I am pretty sure I have narrowed it down to this 
 * 
 * HOLY FUCKING SHIT, I FOUND IT I THINK!!! I WASNT REMOVING THE 7TH FUCKING
 * QUEEN AFTER I PLACED IT GODDDAMN IT! ... THAT WAS IT LETS GOOOOOOOO*/
 
/* arrays to keep track of which rows, and diagonals are occupied. 
 * slashDiag = row + col. backslashDiag = row - col + 7*/
//board[8][8] will be in form row, col. So y, then x.
bool rowTaken[8], slashDiag[15], backslashDiag[15], board[8][8];

//stack <int> q;
int queenY[8];
int cnt = 0;

bool queenable(int x, int y) {
	if (rowTaken[y] or slashDiag[x + y] or backslashDiag[x - y + 7] or board[y][x]) {
		return false;
	} else {
		return true;
	}
}
//GASP, ERROR COULD BE HERE. With 0 based indexing, it should be +7, not +8!
void placeQueen(int x, int y) {
	rowTaken[y] = true;
	slashDiag[x + y] = true;
	backslashDiag[x - y + 7] = true;
}

void removeQueen (int x, int y) {
	rowTaken[y] = false;
	slashDiag[x + y] = false;
	backslashDiag[x - y + 7] = false;
}

//depth is col(x), i is row(y).
void backtracking() {
	int depth = 0; //depth corresponds to which queen we are on. Originally global, but should be local to function	
	while (depth >= 0) {
		bool queenPlaced = false;
		int i = queenY[depth];
		while (i < 8) {
			if (queenable(depth, i)) {
				placeQueen(depth, i);
				queenY[depth] = i;
				queenPlaced = true;
				break;
			}
			i++;
		}
		/* Here I'm realizing for loop like this doesn't work. If we
		 * wanna do something like this you have to keep track of which i
		 * a given queen was on. I figure this can be done through an array.*/
		if (queenPlaced == true) {
			// cout << "Queen placed: (" << depth << ", " << queenY[depth] << ") \n"; This debugging line saved the day.
			if (depth == 7) { //Now that I moved indexing to zero-based, this check should check for 7.
				cnt += 1;
				//cout << "\n" << "Solution: ";
				//for (int i = 0; i < 8; i++) {
					//cout << queenY[i] << " ";
				//}
				//it's funny how the logic here semantically is kind of similar
				removeQueen(depth, queenY[depth]);
				queenY[depth] += 1; //move onto next Y in column OH SHIT THIS IS WHAT WAS WRONG (maybe?).
				queenPlaced = false; //was this the missing line? July 13th: now I know the next line was the missing line

				/*All the logic that should occur if queen is not placeable should happen when queen at final depth is placed.
				* To avoid code redundancy probably better to just include logic earlier in the process. Nvm actually,
				* since in this scenario depth shouldn't change. Although I am not sure if this actually is the issue
				* as in the last depth there should be no other possible squares... */
			} else {
				depth += 1;
			}
			continue;
		} else { //If queen couldn't be placed at current depth.
			queenY[depth] = 0; //Reset queenY for this col, as all squares will be checkable again
			depth -= 1; //Go up a depth
			removeQueen(depth, queenY[depth]); //Remove queen, WITH PROPER COORDINATES
			//cout << "Queen #" << depth << " removed." << "\n"; This wassome expert debugging. Props.
			queenY[depth] += 1; //Check next y, otherwise infinite loop. F YES MADE IT TTO DEPTH 7!!!
		}
	}
}

/* LOL I'm such a dumbass. I was like why is it returning 0? 
 * When I had filled every bool in board with a non-zero value (I had no if
 * s[j] == '*' line originally, and instead said board[i][j] = s[j],
 * so of course queenable() just saw a filled board.*/
 
/*I REALIZED ANOTHER MAIN ERROR, when I remove queen and go up a depth,
 * I wasn't resetting queenY[] for the current depth, as all nodes should
 * now be open for attempt. 
 * 
 * ANOTHER ONE: removeQueen() was using wrong queenY as I was incrementing it
 * preemptively before next loop. Wait... it was in if condition, so maybe not?
 * 
 * GODDAMN IT, WHYD I USE NON-ZERO based INDEXING FOR DEPTH, it's throwing off number
 * system. So I need to rework depth make it zero based, or else change
 * all of my f'ing arrays and shit.*/
 

int main()
{
	string s;
	for (int i = 0; i < 8; i++) {
		cin >> s;
		for (int j = 0; j < 8; j++) {
			if (s[j] == '*') {
				board[i][j] = true; 
			}
		}
	}
	
	backtracking();
	
	cout << "\n" << cnt; //OMFG, I WAS RETURNING QUEEN Y NOT CNT AND I WAS SO FUCKING CONFUSEDD AAAAHHHHH
	//currently only cnt of 1... why you be like this.
	cin >> s;
	return 0;
}
