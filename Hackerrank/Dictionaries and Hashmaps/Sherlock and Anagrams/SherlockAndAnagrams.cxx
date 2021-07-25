#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9

struct letCount {
	int cnt[26];
	
	letCount() {
		memset(cnt, 0, sizeof(cnt));
	}
	
	void clear() {
		memset(cnt, 0, sizeof(cnt));
		return;
	}
	
	bool operator == (const letCount &b) const {
		for (int i = 0; i < 26; i++) {
			if (this -> cnt[i] != b.cnt[i]) {
				return false;
			}
		}
		return true;
	}
};

class myHash {
public:
	size_t operator()(const letCount& tracker) const {
		size_t h = 37;
		for (int i = 0; i < 26; i++) {
			h = (h * 54059) ^ (tracker.cnt[i] * 76963);
		}
		return h;
	}
};

void printTracker(letCount& tracker) {
	for (int i = 0; i < 26; i++) {
		if (tracker.cnt[i]) {
			for (int j = 0; j < tracker.cnt[i]; j++) {
				cout << char('a' + i) << " ";
			}
		}
	}
	cout << endl;
	return;
}

int sherlockAndAnagrams(string s) {
	unordered_map<letCount, int, myHash> forward;
	
	int ans = 0;
	letCount tracker;
	for (int i = 0; i < s.size(); i++) {
		for (int j = 0; i + j < s.size(); j++) {
			tracker.cnt[s[i + j] - 'a'] += 1;
			// printTracker(tracker);
			if (forward.count(tracker)) {
				ans += forward[tracker];
			}
			forward[tracker] += 1;
		}
		tracker.clear();
	}
	
	tracker.cnt['k' - 'a'] = 1;
	// cout << forward[tracker];
	return ans;
}

int main()
{
	cout << sherlockAndAnagrams("kkkk");
	return 0;
}

/* So issue with original solution (where I iterate through backwards in same 
 * manner as forwards), is that it double counts individual letters, as on the 
 * way backwards it will match a specific letter at its own position to itself.
 * The other thing it does is it will match the whole string to itself if the whole
 * string is a palindrome (which shouldn't be counted as its the same substring).
 * 
 * So instead, what we should do is in the first for loop, as we iterate forwards,
 * reverse the stringFragment, and check the map for any corresponding counts. Add
 * them if they exist, move on otherwise. This should all add up fine, and we don't
 * miss anything.
 * 
 * So reverseFragment method was wrong too, as I misinterpreted the problem. An anagram
 * is just any string which can be rearranged to the other (i.e.: it has the same number
 * of each letter). So I'm working on doing that for a hashmap rn by creating my own
 * user defined struct that tracks the number of  each letter in a string fragment.*/
 
/* Ah, so I made an oopsie again. I was using forward.count(tracker) instead of just
 * forward[tracker] where I wanted the number of trackers that had id tracker lol. Count
 * was always just gonna give 0 or 1 depending on whether or not the key existed. God I'm
 * dumb sometimes. */
 
/* Takeaway: Make hash function for user-defined classes if you want to use it as key
 * for unordered_map. Hash function should be wrapped as struct or class to pass it to
 * template args of unordered_map at declaration.
 * 
 * If using map to keep count of how many things with given key exist or whatever,
 * careful not to get unordered_map.count() confused with unordered_map[key]. The
 * latter gives you what you're looking for, the first just checks whether or not
 * the key exists lol. Good stuff.*/
