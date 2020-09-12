#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 1e5 + 10;

int n, k, a[MAXN], seg[MAXN<<2], lz[MAXN<<2];
vector<int> vec[MAXN];

void pushDown(int v){
	if (!lz[v]) return;
	lz[v<<1] += lz[v];
	lz[v<<1^1] += lz[v];
	seg[v<<1] += lz[v];
	seg[v<<1^1] += lz[v];
	lz[v] = 0;
}

void add(int v, int b, int e, int l, int r, int val){
	if (l <= b && e <= r){
		seg[v] += val;
		lz[v] += val;
		return;
	}
	if (r <= b || e <= l) return;

	int mid = b + e >> 1;
	pushDown(v);
	add(v<<1, b, mid, l, r, val);
	add(v<<1^1, mid, e, l, r, val);
	seg[v] = max(seg[v<<1], seg[v<<1^1]);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int te;	cin >> te;
	for (int w = 1; w <= te; w++){
		cout << "Case #" << w << ": ";
		cin >> n >> k;
		int ans = 0;
		fill(seg, seg + 4*(n+2), 0);
		fill(lz, lz + 4*(n+2), 0);
		for (int i = 0; i < n; i++){
			cin >> a[i];
			vec[a[i]].push_back(i);
			add(1, 0, n, 0, i+1, 1);

			int sz = vec[a[i]].size();
			if (sz > k){
				add(1, 0, n, 0, vec[a[i]][sz-k-1]+1, -1);
				if (sz > k+1)
					add(1, 0, n, 0, vec[a[i]][sz-k-2]+1, k);
				add(1, 0, n, 0, vec[a[i]][sz-k-1]+1, -k);
			}

			ans = max(ans, seg[1]);
		}


		for (int i = 0; i < n; i++)
			vec[a[i]].resize(0);
		cout << ans << "\n";
	}
	return 0;
}
