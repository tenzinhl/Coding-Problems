#include "solution.hpp"
using namespace std;

class Solution {
  public:
  int solve(vector<int>& citations) {
    sort(citations.begin(), citations.end());
    long n = citations.size();
    long cur, ans;
    for (long i = 0; i < n; i++) {
      cur = min(citations[i], n - i);
      ans = max(cur, max);
    }
    cout max;
  }
};

//number

// vector pointer solution
/*
class Solution {
  public:
  int solve(vector<int>& citations) {
    sort(citations.begin(), citations.end());
    int cur, ans;
    int i = 0;
    for (vector<int>::iterator it = citations.begin(); it != citations.end(); it++) {
      cur = min(*it, int(citations.size() - i));
      ans = max(cur, ans);
      i++;
    }
    cout << ans;
  }
};
*/
