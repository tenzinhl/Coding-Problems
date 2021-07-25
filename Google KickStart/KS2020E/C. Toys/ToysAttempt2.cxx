#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9
#define LIM (int) (1e5 + 8)
int e[LIM], r[LIM], tsize;
pair<int, int> gr[LIM];
ll tree[LIM << 2];
priority_queue<int, vector<int>, greater<int>> pq;

void update(int ind, int val) {
	ind += tsize;
	tree[ind] = val;
	while (ind > 1) {
		ind >>= 1;
		tree[ind] = tree[ind * 2] + tree[ind * 2 + 1];
	}
	return;
}

ll query(int b, int en, int ind = 1, int l = 0, int ri = tsize - 1) {
	if (b <= l and en >= ri) {
		return tree[ind];
	}
	int mid = (ri + l) / 2; // left leaning
	ll ans = 0;
	if (b <= mid) {
		ans += query(b, en, ind * 2, l, mid);
	}
	if (en > mid) {
		ans += query(b, en, ind * 2 + 1, mid + 1, ri);
	}
	return ans;
}

void solve() {
	int n;
	cin >> n;
	
	tsize = 1;
	while (tsize < n) {
		tsize <<= 1;
	}
	long long ttot = 0;
	for (int i = 0; i < n; i++) {
		cin >> e[i] >> r[i];
		gr[i] = make_pair(e[i] + r[i], i);
		update(i, e[i]);
		ttot += e[i];
	}
	const ll TOT = ttot;
	// Ttot >= Ri + Ei
	sort(gr, gr + n, greater<pair<int,int>>());
	int z = 0;
	while (z < n) {
		if (ttot < gr[z].first) {
			ttot -= (e[gr[z].second]);
		} else {
			cout << z << " INDEFINITELY\n";
			return;
		}
		z += 1;
	}
	// Reaching this point in the code means forming an indefinite loop is impossible, now we try to find best non-indefinite
	// set of toys
	ttot = TOT;
	z = 0;
	while (gr[z].first > ttot and z < n) {
		pq.push(gr[z].second);
		z += 1;
	}
	int removedCnt = 0, tremovedCnt = 0, curBreakpoint;
	ll ans = 0, tans;
	while (!pq.empty()) {
		curBreakpoint = pq.top();
		pq.pop();
		tans = ttot + query(0, curBreakpoint) - e[curBreakpoint]; // weird subtraction is equivalent to query(0, curBreakpoint - 1), but it avoids OOB error
		if (tans > ans) {
			ans = tans;
			removedCnt = tremovedCnt;
		}
		// Now we remove this breakpoint
		update(curBreakpoint, 0); // Artificially remove from tree by setting E value to 0
		ttot -= e[curBreakpoint];
		tremovedCnt += 1;
		// add any other toys that now become breakpoints to the priority queue
		while (gr[z].first > ttot and z < n) {
			pq.push(gr[z].second);
			z += 1;
		}
	}
	cout << removedCnt << " " << ans << "\n";
	// memset(tree, 0, sizeof(ll) * LIM * 4); This lin
	return;
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

// HOLY shit that might actually be the solution, lol!

/* So we do want to remove next immediate breakpoint, but that isn't necessarily next largest Ei + Ri... (i.e.: gr[i])
 * Frikkkkk.... I thought I had it. Spent all this time implementing segment tree too. Thinking.
 * OK, no need to freak out. We just push all indices with gr[i] > ttot into a priority queue, lowest indices
 * removed first.*/

//~ Below text is actually earlier in thought process, moved here from inside function: ~//---------------------------
// for non-indefinite, We choose whether to take or not take toy. Each toy we do take will be visited at least once,
// some visited twice. A taken toy is visited twice if ttot of all other taken toys >= Ri, and if no toy before this
// was a breakpoint (if no toy before this failed this condition).
// There is only one option! For any set of toys, there will only be one breakpoint that matters, the first one! Removing
/* any other toys besides this breakpoint would be pointless, so we greedily remove breakpoint, and compare ttot of
 * this solution to a running maximum that we keep track of! noice.
 * (once again) A toy is a breakpoint if: Ttot - Ei >= Ri, i.e.: Ttot >= Ei + Ri
 * The value of a solution: Ttot + (add the Ei of any nodes that aren't breakpoint as we go through loop since it would
 * be reached twice, and subtract the Ei of any breakpoints we remove (since they are never visited)) IGNORE This, wrong. */

/* Update: nvm, removing the breakpoint toy can cause earlier toys to become breakpoint, which would change score
 * calculation (it would become rather complex), so this solution is not thorough (or even correct).
 * 
 * HOLD UP, I think the idea of removing first available breakpoint greedily is still correct! Because is pointless
 * to remove non-current-breakpoint toys. The change, is that we don't remove breakpoints linearly. We use the
 * sorted array of (Ei + Ri)'s, and remove that way, then we calculate score for every arrangement. How to calculate
 * is the question.
 * Genius? We calculate prefix sum of Ei's for all toys in the circle, and add that (given index of breakpoint), and
 * then we subtract Ei of removed toys (although toys that were before current point that have been removed would
 * need to be subtracted twice...) We could use a segment tree lol, but that seems unecessary... right? Wait, that
 * might actually be the key. So time calculation for given breakpoint:
 * 	ttot (of current arrangment) + queryTree(0, curIndex - 1).*/

/* Takeaways (i.e.: what went wrong):
 *  1. I'm reviewing code, and I put (right - left) / 2 for calculating middle in tree query, when it should be
 *     (right + left) / 2. It's these types of small errors that are HUGE but hard to find. Goddamn it.
 *  2. When passing function to class template in the <>'s you do not add parantheses "()". HOWEVER, when passing
 *     a function to another function (like sort()) you do add the parantheses. Not a huge issue as compiler spots
 *     it and it's a fast enough fix.
 *  3. Always remember to reset global arrays/variables. (forgot to memset the tree this time).
 *  4. I need to work on thinking up edge cases.
 *  5. DOUBLE DOUBLE CHECK variable initializations. Sometimes the variable needs a better default value, and
 *     a surprising amount of the time it hasn't been initialized at all. Today's investigation (see dumbstuff
 *     CompilerAndVariableInitialization to see example of compiler missing rel. obvious uninitialization).
 * 	6. Less obvious, but important. When doing the algebra, try to arrange equations so you have total sums, and
 *     get all constant variables (here it was Ri and Ei) on same side of equation so they can be grouped in
 *     a single variable and easily compared. Good variables to try and work towards in computer algebra: Total sum,
 *     prefix sums, all constants on one side, etc.
 * 
 * Interesting Notes:
 * I thought not resetting tree array was an issue, but with how update() is written (and with the loop setup)
 * tree does not need to be reset, since all necessary leaves are updated in the input loop, and there should
 * be no OOB access as we only query up to (0, n-1). Nice.
 * So I'm reading editorial (10:32 PM), and they avoided using segment tree by going through and adding and 
 * removing toys as they go. Something I should look into, maybe try and implement.
 * OMG, I originally thought I could iterate through breakpoints 1 to N. I WAS RIGHT, THATS WHAT the editorial
 * does, you just remove the breakpoint behind you as you gooo... I need to understand this... *reading* YUP,
 * it was my original idea. IDK, I guess I saw ghosts somewhere along the line and pursued this segment tree
 * line of thought. You can iterate through in order, because on Lil' Timmy's second round through the toys
 * the breakpoint that matters... nvm I still don't intuitively get it. I'll think more.
 * 
 * OOOhh okay. So when you remove a breakpoint, the ghost I saw (and a real one at that), is that
 * earlier toys could then become breakpoints, which would then have to be removed if you wanted to continute.
 * This is very true, however the thing I failed to realize, is that to get a better score than stopping at
 * this initial breakpoint, you'd have to visit the toy beyond this breakpoint, which requires clearing all
 * earlier toys (that have changed to breakpoints). Since stopping at any breakpoint in the middle WOULD HAVE
 * TO have a lower time that stopping at this initial one (since it's later in the queue, and hasn't removed
 * anything yet). (All of those breakpoints that are new and emerge are like prefix sums of this breakpoint
 * prime, and even less than that technically as toys get removed). AND THAT, is the reason you can iterate
 * through 1 to N.*/

/* OK, nobody freak out, but there were very few compilation errors, and on my first submit this bad boy got all
 * sample cases right. YEEEEAAAAHHHH. Of course, Kickstart has really weak sample cases, but still, noice.
 * 
 * yeah ok, we got WA on first test set lol. I still have so many nerves when submitting, hopefully this
 * subsides as I do more comp programming. (probably same as performing, it's just weird when that I feel this
 * way even when it's not an actual live competition scenario. */

/* End of the day (10:30 pm) IT GOT ACCEPTED LET'S  GOOOOOO. This type of methodical, thorough, problemsolving
 * feels so rewarding. GOOD JOB MY MANNNNN LETS FRIKKKINN GOOOOOOOO. You are awesome. Keep it up. I think all
 * of the takeaways are up to date. So in the end, the main error was that uninitialized tremovedCnt lol. ALRIGHT!
 * it's the small fatal errors. Double checking variable initialization IS HUGE priority going forward.
 * STILL, AWESOME JOB bro.*/
