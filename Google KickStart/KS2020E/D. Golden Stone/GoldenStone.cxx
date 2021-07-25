#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9

void solve() {
	
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

/* Okay, so this problem reminds me of the delivery problem from the facebook
 * Hacker cup (the one where you have to refuel along the way and you have to find
 * the cheapest price to reach your destination). So that one used a segment tree
 * where each leaf represented the minimum cost to have a full gas tank at that
 * distance from the target node, (so a leaf would account for branches along the
 * main path). 
 * 
 * Here, I was thinking we could do a similar thing where for each node we store
 * an array of the cheapest price per producing a stone of a given type at that node (for stones that can't
 * be produced at the current moment, we set it's cost to INF).
 * We go through the recipes and update the lists if a recipe allows a node to produce
 * a stone type more cheaply. The issue I'm seeing is that recipes can, and will at times,
 * affect the price of other recipes (assuming it makes it cheaper). Is it possible
 * to know what order to do the recipes in? Or do we keep looping through them until
 * a price does not change?
 * 
 * Let's talk about recipe order. We know that some recipes are not worth it.
 * If there is a recipe that produces a stone of type b, but requires a stone of
 * type b too, we can ignore it (since we would never gain anything from using that
 * recipe). */

/* At the very least I know that it is possible to populate all nodes with 
 * the price of carrying a stone there (from a city that has it in supply) in
 * O(S * N^2), by just dfs'ing from each node and updating price if it is lower.
 * (As an aside, technically bfs would allow us to do it in just (S * N), but
 * given how low the bounds are, O(S * N^2) should be fine.  */
 
/* So I'm reading editorial. Good thinking my guy! I was on a very good track. I
 * properly thought to make graph of optimal cost of stone at given node, and was
 * also correct to set initial cost of unmakeable stones to INF. Slight diff, and
 * I wonder if it's revolutionary, is that instead of each junction just being an
 * array of prices, it says to think of each stone + junction combination as a node.
 * 
 * So I was on the right track... finished the editorial. I don't get quite how solution
 * works ordering wise, don't you need to keep applying recipes? Was I seeing ghosts? idk.
 * I found it, they just say "it can be proven that for each junction no more than N * S
 * iterations are needed to fully optimize cost". wtf. I need to think about that. DAMN I
 * WAS CLOSE THEN, BECAUSE I WAS THINKING THAT THERE MUST BE A REASONABLE LIMIT TO HOW
 * MANY TIMES you have to go over graph before it can't be optimized anymore. I saw ghosts
 * and didn't want to think it through. That has been my downfall... Sadge.
 * 
 * AH SHIT WHAT. SO I AM KIND OF SMART BUT NOT. Instead of iterating through each connection
 * in a node bfs style... WAIT NVM. MY IDEA WAS GOOD, MY BIG O ANALYSIS was SHITE. it's not
 * O(s * n^2) to dfs for example, it would just be S * Edges. omg I'm dumb. */
