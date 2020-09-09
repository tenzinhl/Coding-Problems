#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9
#define LIM 208

int R, G, B;
int r[LIM], g[LIM], b[LIM];
int dp[LIM][LIM][LIM];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> R >> G >> B;
	for (int i = 0; i < R; i++) {
		cin >> r[i];
	}
	for (int i = 0; i < G; i++) {
		cin >> g[i];
	}
	for (int i = 0; i < B; i++) {
		cin >> b[i];
	}
	
	sort(r, r + R, sizeof(r), greater<int>);
	sort(g, g + G, sizeof(g), greater<int>);
	sort(b, b + B, sizeof(b), greater<int>);
	dp[0][0][0] = max(r[0] * g[0], max(g[0] * b[0], r[0] * b[0]));
	for (int ri = 0; ri < R; ri++) {
		for (int gi = 0; gi < G; gi++) {
			for (int bi = 0; bi < B; bi++) {
				if (ri + 1 < R and gi + 1 < G)
					dp[ri + 1][gi + 1][bi] = dp[ri][gi][bi] + r[ri + 1] * g[gi + 1];
				if (gi + 1 < G and bi + 1 < B) 
					dp[ri][gi + 1][bi + 1] = dp[ri][gi][bi] + g[gi + 1] * b[bi + 1];
				if (ri + 1 < R and bi + 1 < B)
					dp[ri + 1][gi]
			}
		}
	} 
	return 0;
}

/* KEY TAKEAWAY: 
 * I'm upset I didn't solve this on my own, but the roadblock in my original thinking
 * was forgetting that Dynamic Programming is all about storing infromation about a state.
 * In this case the state has 3-dimensions. Because it's just a state you don't have to 
 * traverse the array in single dimensions only. Here you take pairs of (pairs of) sticks
 * at a time, so it makes natural sense to populate your dp array by updating a position
 * that differs in more than one dimension (two in this case). I for some reason limited
 * myself to one dimensional updating just because the for loop runs first. 
 * 
 * You can update any position related to your current one, shifting in more than one
 * *property* of the state. (IMPORTANT Remember you dp is about storing properties,
 * you can store as many as you want, and that you don't just have to think about them
 * as dimensions).*/
