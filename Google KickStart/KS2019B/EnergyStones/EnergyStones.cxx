#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 1e9

#define LIM 108
int n, s[LIM], e[LIM], l[LIM];
int val[LIM][10'008]; // stores value of stone i at a given time.

bool eaten[LIM];
// max amount of time to eat all stones is 10,000
/* Current thought is that you want to minimize energy loss at each turn.
 * Since number of stones is small, we can iterate through all remaining stones
 * every step, checking to see eating which one minimizes loss. Heck, O(n^3) should be fine.
 * 
 * We can precalculate value of a stone at any given time.*/
 
void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i] >> e[i] >> l[i];
	}
	
	for (int i = 0; i < n; i++) {
		val[i][0] = e[i];
		for (int t = 1; t < 10'008; t++) {
			val[i][t] = max(0, val[i][t-1] - l[i]);
		}
	}
	
	int toEat = 0; // index of which stone we will eat.
	long long potLoss = 0;
	long long curMin = (ll) INF * INF;
	int curT = 0;
	int tSeg = 0;
	
	long long energy = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (eaten[j]) {
				continue;
			}
			tSeg = s[j];
			for (int z = 0; z < n; z++) {
				if (eaten[z] or z == j) {
					continue;
				}
				potLoss -= (val[z][curT + tSeg] - val[z][curT]); // KEY IS TO REMEMBER this returns a negative number lol.
			}
			// cout << i << ' ' << j << ' ' << potLoss << "\n";
			if (potLoss < curMin) {
				toEat = j;
				curMin = potLoss;
			}
			potLoss = 0;
		}
		eaten[toEat] = true;
		cout << "stone: " << toEat << "\n";
		energy += val[toEat][curT];
		curT += s[toEat];
		curMin = INF;
	}
	
	memset(eaten, 0, sizeof(eaten));
	memset(val, 0, sizeof(val));
	cout << energy << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": ";
		solve();
	}
	return 0;
}

/* I think I did a great job, HELL I DID FANTASTIC. I figured out the key point of minimizing loss,
 * and came up with a novel solution with a suitable time complexity.
 * Can't find a test case that doesn't work yet. Google's thing is just telling me WA. 
 * 
 * GOOD. So I have figured out why this solution is wrong. It was so upsetting not being able to understand,
 * and to be fair it is because I did not spend the time to develop a full systematic understanding of the 
 * problem (to gain intuition). I was just thinking about minimizing the loss rate of the pile as you go, 
 * forgetting that that is only a factor to the answer. To optimize answer you must minimize loss overall,
 * and loss overall is loss rate * amount of time spent eating... wait I still don't have a full intuition, 
 * but the idea is there. In the first test case, this could mena eating two larger stones rather than three
 * over time.
 * 
 * ANOTHER KEY REALIZATION I TOTALLY MISSED, and this really helps develop intuition, is that for a given stone,
 * once it's value hits 0, it's functional loss rate drops to 0 too for the rest of the problem! So program is only considering instantaneous loss
 * rate, not realizing that in a long term solution, leaving a given stone alone may be fine as it's average loss rate
 * would be lower than it's instantaneous, as it's loss rate hits 0 at some point. OKAY.*/

// I'll come back to this, prolly in a new file
