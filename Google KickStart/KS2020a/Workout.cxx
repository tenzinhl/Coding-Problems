#include <bits/stdc++.h>
using namespace std;

int solve() {
	int n, k;
	cin >> n >> k;
	int a[n];
	int dif[n-1];
	int ddif[n-1];
	
	for (int i = 0; i<n; i++){
		cin >> a[i];
	}
	for (int i=0; i+1<n; i++){
		dif[i] = a[i+1] - a[i];
	}
	
	for (int i=0; i+1<n; i++){
		ddif[i] = dif[i];
	}
	
	 //for (auto c:ddif){
		 //cout<<c<<" ";
	 //}
	 //cout<<endl;
	
	int tdiv[n-1];
	memset(tdiv, 0, sizeof(tdiv));
	
	 //for (auto c:tdiv){
		 //cout << c <<endl;
	 //}
	
	int m = dif[0];
	for(int i=0; i<k; i++){
		for (int i=0; i<n; i++){
			if (ddif[i] >= m){
				//cout << dif[i] << " " << tdiv[i]+2 <<endl;
				ddif[i]=(dif[i]+tdiv[i]+1)/(tdiv[i]+2);
				//cout<<ddif[i] <<" ";
				tdiv[i]++;
				m=0;
				for(int j=0; j<n-1; j++){
					m = max(m, ddif[j]);
				}
				//cout << m << "\n";
				break;
			}
			continue;
		}
int t;
int main(){
	cin >> t;
	for(int caseno=1; caseno<=t; caseno++){
		solve();
		}
		cout << "Case #" << caseno << ": " << m <<endl;
	}
	return 0;
}

