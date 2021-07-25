#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9
#define LIM 1008

// Current issue: WA on first test set
// LOL THIS WAS SUPPOSED TO BE A DP problem. 
int n, k;
pair<int, int> pa[LIM];
int p[LIM], a[LIM];
vector<int> dist[LIM];
vector<int> colors;
bool cfound[LIM];
void solve() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (!cfound[a[i]]) {
			cfound[a[i]] = true;
			colors.push_back(a[i]);
		}
	}
	
	for (int i = 0; i < n; i++) {
		pa[i] = make_pair(p[i], a[i]);
	}
	
	sort(pa, pa + n);
	
	int pt, at;
	for (int i = 0; i < n; i++) {
		pt = pa[i].first;
		at = pa[i].second;
		if (dist[at].empty()) {
			dist[at].push_back(pt);
		} else {
			dist[at].push_back(pt - dist[at].back());
		}
	}
	
	int modifier = 2, sum = 0, ans = INF;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (auto &color : colors) { // Colors is max of n
		for (auto color2 : colors) { // Looping through each distance for each color should total to n
			if (color2 == color) modifier = 1;
			else modifier = 2;
			for (auto d : dist[color2]) {
				pq.push(d * modifier);
			}
		}
		for (int i = 0; i < k; i++) {
			sum += pq.top();
			pq.pop();
		}
		ans = min(sum, ans);
		sum = 0;
		pq = priority_queue<int, vector<int>, greater<int>>();
	}
	cout << ans << "\n";
	// Reset dist, colors, cfound (arr.vectors, vector, arr)
	for (auto &v : dist) {
		v.clear();
	}
	colors.clear();
	memset(cfound, 0, sizeof(cfound));
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

/* So, I'm thinking priority queue (or binary heap). So to populate queue takes
 * O(NlogN), and since we need to do that N times (each time switching which dog type
 * (or color whatever) is the last one we do (the one where the weights are 0).*/
 
 /* 
  * Test input
3
6 6
4 3 3 1 3 10000
1 2 8 9 5 7
4 3
1 2 4 9
3 3 2 3
4 3
1 2 3 4
1 8 1 8
* answers: 8, 6, 10028 (not necessarily in order);
* So when we put 10028 test case first, program gets messed up, nvm, I didn't
* copy test case properly.
* */

/* Key lesson: I originally thought this may be a dp problem. The key is to
 * realize that since we only need to try dogs of a given color once, we can
 * make this a dp problem (and since optimal subproblems overlap). The key is 
 * to make one of the values in the dp array the condition of which color dogs
 * have we tried. (The first i colors). This way it can become dp. Even though
 * there wasn't a clear order here, the fact that a color only needs to be visited
 * once means we only need to consider it once, and thus can be used as a condition
 * in a dp array. I am still unsure why my approach is getting WA. I hope it's not
 * a fundamental issue with the approach, that would make me sad. Need to
 * think it over.
 * 
 * OMG I'm a dumbass. Of course my solution (at least how it's implemented currently)
 * doesn't work. I just sort the distances like it's nothing, BUT THEY NEED TO BE done
 * in a certain order, since some come after others, yet my solution just sorts them all
 * willy nilly. Okay, that's kind of duh, can't believe I missed that. So based off
 * of this my solution is unlikely to pass TL, as it would need to maintain a priority
 * queue still, but only consisting of possible moves, and then pushing each next possible
 * move after a move is made (and I don't even know how I'd be able to keep track of that).
 * pairs maybe? it gets kind of obfuscated.*/

/* Test cases:
 * 1
 * */
