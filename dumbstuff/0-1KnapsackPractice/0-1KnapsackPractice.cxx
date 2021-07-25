#include <bits/stdc++.h>
using namespace std;

int dp[2008][2008];
long long solve() {
    int s, n;
    cin >> s >> n;
    int val[2008], weight[2008];
    for (int i = 0; i < n; i++) {
        cin >> weight[i] >> val[i];
    }
    
    memset(dp, 0, sizeof(dp));
    
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= s; w++) {	
            if (w - weight[i-1] < 0) {
                dp[i][w] = dp[i-1][w];
            } else {
                dp[i][w] = max(dp[i-1][w], val[i-1] + dp[i-1][w-weight[i-1]]);
                // OH MY GOODNESS. I have no idea how this didn't give OOB error.
                // I guess it was accessing memory the OS was letting me have.
                // but still surprised nothing complained. i-1 IS OUTSIDE of DP's
                // boundaries. Crazy.
            }
        }
    }
    return dp[n-1][s];
}
// What is the max value I can obtain for a given weight using the first n items.
// This is a state we can store in DP that also helps answer further questions.

/*
further question and answer: if we include i + 1 and it's less
*/

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cout << solve() << "\n";
    }
    return 0;
}
