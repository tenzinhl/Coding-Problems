#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9

/* My assumptions:
 * 	-Motor speed data and target data are sent constantly
 * 		-So even when controller isn't moving, motor input will still come
 * 		 and will be (0, 0).
 * 	-There may be input error (data corruption, idk)
 * 	-There are never more than 10 targets. */

// I was thinking of making 1 and 2 reserved codes, so if they are sent in the 
// middle of a packet it throws an error but idk. Below I assume they aren't reserved.
// i.e.: You can have a motor speed of 1mm/sec haha.

/* Main class. Parses words, stores input information in private variables.
 * Putting it all in a class to avoid name collisions. (I'm new to using classes
 * so forgive me if this is garbage lol).
 */
class WordParser {
public: // Just make it all public so I don't have to worry about scope LOL
	int leftSpeed = 0;
	int rightSpeed = 0;
	pair<int, int> targets[10]; // pair.first = x-coord; pair.second = y-coord;
	int numberOfTargets = 0;
	
	int parseType = 0;
	int expectedWordsRemaining = 0;
	int parseWord(int word) {
		int errorCode = 0;
		
		// base-state. Either just finished a message or just started.
		if (parseType == 0) {
			if (word == 1 or word == 2) {
				parseType = word;
				if (word == 1) {
					expectedWordsRemaining = 2;
				}
			} else {
				// If protocol is broken, set error code flag
				parseType = 0;
				errorCode = 1;
			}
			return errorCode;
		}
		
		if (parseType == 1) {
			if (expectedWordsRemaining == 2) {
				leftSpeed = word;
			} else if (expectedWordsRemaining == 1) {
				rightSpeed = word;
			}
			expectedWordsRemaining -= 1;
		}
		
		int targetNumber = 0; // Stores which target we are on.
		if (parseType == 2) {
			if (expectedWordsRemaining == 0) {
				expectedWordsRemaining = word * 2;
				
				// Checks if the number of targets has decreased and then clears old targets if so
				if (numberOfTargets > word) {
					for (int i = word; i < numberOfTargets; i++) {
						targets[i] = make_pair(-1, -1); // Define null target as coord (-1, -1)
					}
				}
				numberOfTargets = word; // update numberOfTargets to reflect new value
			} else {
				targetNumber = (expectedWordsRemaining + 1) / 2; // Gives 1-based index of target we are on
				if (expectedWordsRemaining % 2 == 0) {
					targets[targetNumber - 1].first = word;
				} else {
					targets[targetNumber - 1].second = word;
				}
				expectedWordsRemaining -= 1;
			}
		}
		
		// Runs if packet has finished.
		if (expectedWordsRemaining == 0) {
			parseType = 0;
		}
		return 0;
	}
	// Default constructor for this class.
	WordParser() {
		leftSpeed = 0;
		rightSpeed = 0;
		// Initialize target coords to null value of (-1, -1)
		for (int i = 0; i < 10; i++) {
			targets[i] = make_pair(-1, -1);
		}
		numberOfTargets = 0;
		parseType = 0;
		expectedWordsRemaining = 0;
	}
};

// placeholder main function so I can compile but also test code.
int main() {
	WordParser parser;
	int words[9] = {
		1, 50, -20, // Motor instruction packet
		2, 2, 20, 30, 40, 50 // 2-Target packet
	};
	
	for (int i = 0; i < 9; i++) {
		parser.parseWord(words[i]);
		// cout << "i: " << i << " parseType: " << parser.parseType << " expectedWords: " << parser.expectedWordsRemaining << endl;
		// This was a debugging line.
	}
	
	cout << "Right Speed is: " << parser.rightSpeed << endl; // should be -20
	cout << "2nd Target's coordinates: " << parser.targets[0].first << " " << parser.targets[0].second << endl; // 40, 50
	// because of implementation target indices are backwards. (First target input will be at end of array etc.)
	cout << "3rd Target's coordinates: " << parser.targets[2].first << " " << parser.targets[2].second << endl; // -1, -1
	return 0;
}
