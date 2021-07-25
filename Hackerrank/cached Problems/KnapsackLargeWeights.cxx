#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF (int) 2e9

bool dp[(int) 1e6][43];
char state[42];
long long suffixSums[42]; // sum of all remaining sorted weights including current index
int weightCapacity(vector<int> weights, int maxCapacity) {
    sort(weights.begin(), weights.end());
    int ans = 0;
    long long curWeight = 0;
    const int n = weights.size();
    suffixSums[n - 1] = weights[n-1];
    for (int i = n - 2; i >= 0; i--) {
        suffixSums[i] = suffixSums[i+1] + weights[i];
    }
    int index = 0;
    while (state[0] >= 0) {
        state[index] = 1;
        curWeight += weights[index];
        if (curWeight > maxCapacity) {
            state[index - 1] = 0;
        }
    }
}

int main()
{
	return 0;
}

