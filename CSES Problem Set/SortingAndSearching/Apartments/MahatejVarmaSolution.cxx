#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define mtv(kit) cout<<#kit<<" - "<<kit<<"\n";
#define ff first
#define ss second
#define pb push_back
#define rep(i,a,b) for(i=a;i<b;i++)
#define pii pair<ll , ll>
#define all(x) x.begin(),x.end()
#define nl "\n"
#define ump unordered_map
 
const ll mod = 1e9+7;
 
void doit(){
    ll n, m, k, i, ans = 0, j;
    cin >> n >> m >> k;
    vector< ll >people(n),apartments(m);
    rep(i,0,n)cin >> people[i];
    rep(i,0,m)cin >> apartments[i];
    sort(all(people));
    sort(all(apartments));
    for(i = 0 , j = 0 ; i < n; i++){
        while(j < m && people[i] - k > apartments[j])j++;
        if(j < m && apartments[j] <= people[i] + k)ans++,j++;
    }
    cout << ans << nl;
}
 
int main() {
// #ifndef ONLINE_JUDGE
//     freopen("input1.txt","r",stdin);
//     freopen("output1.txt","w",stdout);
// #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    // cin >> t;
    for(ll i = 1; i <= t; i++){
        doit();
    }
}
