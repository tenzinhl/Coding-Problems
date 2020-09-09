#include <bits/stdc++.h>
using namespace std;
#define ll long long

set<long> s;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	long n;
	cin >> n;
	long cur;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		s.insert(cur);
	}
	
	cout << s.size();
	return 0;
}

// Takeaways: the two input output lines noticeably improve execution time for
// 10^5 inputs. Time complexity of c++ set.insert() is logN (so overall O(NlogN), which is good enough
// for 10^5 inputs. Could make O(N) time by using self-made array pretty sure.
