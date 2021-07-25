#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9

int charCount[26]; // How many of each character total in the original string remaining
int desiredCharCount[26]; // how many of each character still required in the solution
string reverseShuffleMerge(string s) {
	memset(charCount, 0, sizeof(charCount));
	for (int i = 0; i < s.size(); i++) {
		charCount[s[i]-'a'] += 1;
	}
	
	// Divide charCount values in half, so we know the number of each letter in one solution
	for (int i = 0; i < 26; i++) {
		desiredCharCount[i] = charCount[i] / 2;
	}
	
	int desiredChar = 25; // used to keep index of what char we're aiming for
	while (desiredChar >= 0 and desiredCharCount[desiredChar] <= 0) {
		desiredChar--;
	}
	
	string ans_reversed;
	int curChar;
	// So I deleted old for loop. Thankfully with new logic most of the stuff can be kept the same!
	for (int i = 0; i < s.size(); i++) {
		curChar = s[i] - 'a';
		if (curChar == desiredChar or desiredCharCount[curChar] >= charCount[curChar]) {
			desiredCharCount[curChar] -= 1;
			ans_reversed.push_back(curChar + 'a');
			if (desiredCharCount[desiredChar] <= 0) {
				while (desiredChar >= 0 and desiredCharCount[desiredChar] <= 0) {
					desiredChar--;
				}
			}
		}
		charCount[curChar] -= 1;
	}
	
	string ans;
	// reverse ans_reversed and store in another string
	for (int i = ans_reversed.size() - 1; i >= 0; i--) {
		ans.push_back(ans_reversed[i]);
	}
	return ans;
}

/* My current logic is wrong as being greedy for desired char as I am doing
 * can lead you to a bad route where you're forced to take a bad char early
 * on. e.g.: "abaggb". My current logic skips first b in an attempt to get an
 * 'a', but then is forced to take a g, when taking the b would have been optimal.
 * What if I did it the other way around? Taking every character that isn't desired
 * as greedily as possible, building the string backwards... That would pass my custom
 * test case wouldn't it?
 * 
 * YOOO, the issue with the first direction was we lack information at the critical
 * junction (at the first 'b'), but by going in the opposite direction we have the most
 * information when it matters most, at the beginning of the string. WOAH, does this
 * work??? I will big-time POGGERS if it does.
 * 
 * ugh, closer, but still no cigar. Consider 'bgbgaa', my current logic would give
 * agb, when abg is actually optimal. Does this problem require backtracking? No way,
 * the time complexity would be too high right?
 * 
 * I THINK I HAVE IT. So first we corrected loop direction, now we have to correct
 * desired Char. The desired Char should actually be the worst character in the list.
 * So we get rid of worst of the worst as we go! AGHHH THIS MAKES TOO MUCH SENSE.
 * Since we can't know the best, but we can know what's worst always, and by always
 * removing worst possiblities (by putting worst characters at furthest back part of
 * the string) we can greedily construct the optimal string! I think..
 * 
 * So it didn't work for 'abcdefgabcdefg'. Hrm.... I'll come back to this. I wanna get
 * the roblox problem out of the way.
 * 
 * Key takeaway:
 * (If my fix turns out to be right) Optimizing isn't always just about knowing what's
 * best, it can also just be knowing WHAT IS WORST!!! Probably not for DP, but
 * for greedy algorithms if you can know with absolute certainty the worst possibility,
 * you can eliminate those as you go! NVM, this fix didn't solve it. But I think
 * the idea is still true.
 * 
 * Coming back wayyy later Nov. 16th, I think part of my error is that now when you're
 * iterating forward, I'm forgetting that I'm going backwards through the reversed string.
 * i.e.: once we greedily grab the first g in 'abcdefgabcdefg', AND THEN we hit the
 * 2nd 'a' which we MUST take, we can retroactively shove all the chars we saw into the string
 * to try and get a as early as possible in the string.*/
int main()
{
	return 0;
}

