//Tenzin Low
//AP CS or something like that
//Hello world

//OK, HOLY HSIT, I JUST STARTED TO UNDERSTAND WILLIAM LIN'S MADNESS
//in his winning 2020 round a video. So basically c[][] is like a hodge-podge
//trie. Every value in c[][] stores the "address" of the next node for the
//corresponding prefix. IDK if this is more efficent or not, certainly
//the code is harder to understand lol.

//So then cnt[i] stores the number of strings that end at the corresponding
//node in c[i][]. UPDATE: Count doesn't store the # of strings that end
//at given node. it stores the number that pass through/end at that node
//(are a child of that node). This is better because it simplifies our
//calculation of the score. UPDATE: This is wrong.

//I am still struggling to resolve how this answer resolves the leftover
//strings at end nodes. OH, I was ignoring the cnt[u]+=cnt[c[u][v]] line.

//We can do m++ and let c only have n+1 columns because at worst, if every
//character in every string is part of a unique string with no overlap, we
//will only have at most n nodes. GENIUS.
//----------------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

int t;
int n, k, c[2000001][26], cnt[2000001];
long long ans;

//Attempt at solving problem through defined data structure. May return
//to this.

//typedef struct data {
	//trieNode* children[26];
	//int value;
	//int count;
	//trieNode(int v, trieNode* parent) {
		
//} trie;

//just copied his depthfirstsearch code for now. Mind busted after recent
//breakthrough. Celebrating with some Imogen Heap. 2-3 hours later looking
//at it now:
void dfs(int u = 0, int d = 0) {
	for(int v = 0; v < 26; v++) {
		if(c[u][v]) {
			dfs(c[u][v], d + 1); //lol I had d++ instead of d+1 here for some reason. That definitely wouldn't work as planned lol.
			cnt[u]+=cnt[c[u][v]]; //ah, this line adds the remainders from the
								//deeper node back into the parent node to be used for scoring again.
		}
	}
	while (cnt[u] >= k) {
		cnt[u] -= k;
		ans += d;
	}
}


int solve() {
	cin >> n >> k;
	int m = 1; //can start at one because we gave c[][] n+1 columns.
	for (int i=0; i<n; i++) {
		string s;
		cin >> s;
		int u = 0;
		for (char d:s) {
			if (!c[u][d-'A']) {
				c[u][d-'A'] = m; //m provides a unique key for each node
				m++; //put m++ in a separate line to be clearer.(screw tmwl)
			}
			u = c[u][d-'A'];
		}
		++cnt[u]; //add 1 to count of node. (we only count number of strings that end at node)
	}
	
	ans = 0;
	dfs();
	memset(c, 0, m * sizeof(c[0]));
	memset(cnt, 0, sizeof(int) * m);
	return ans;
}		
	
			
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	cin >> t;
	for (int i = 1; i <= t; i++) {
		solve();
		cout << "Case #" << i << ": " << ans << "\n";
	}
	return 0;
}

//Final note: Well it works! I feel like I learned something today. Thanks William.
//Still want to check out the Trie data structure though, may do that later today or tmrw though.
//I think doing that will just be good for getting used to working with structs, since I've never
//really used those.
