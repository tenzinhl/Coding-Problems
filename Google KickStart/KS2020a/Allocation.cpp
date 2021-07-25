#include <bits/stdc++.h>
using namespace std;

int solve(int N, int B){
	int prices[N];
	for (int i=0;i<N;i++){
	cin >> prices[i];
	}
	int curSum = 0;
	int housesBought = 0;
	sort(prices, prices+N);
	for(auto h : prices){
		curSum += h;
		housesBought +=1;
		if (curSum > B){
			housesBought -= 1;
			return housesBought;
		}
	}
	return housesBought;
}

int main(){
	int T;
	cin >> T;
	for (int i=0; i<T; i++){
		int N,B;
		cin >> N >> B;
		int ans = solve(N,B);
		cout << "Case #" << i+1 << ": " << ans << endl;
	}
	return 0;
}
