long long hashMap(std::vector<std::string> queryType, std::vector<std::vector<int>> query) {
  long long keyShift[(int) 1e5 + 8] = {0};
  long long valueShift[(int) 1e5 + 8] = {0};
  unordered_map<int, pair<int,int>> map; // Assuming that same key won't be inserted twice
  // unordered_map<int, int> pushdate;
  long long ans = 0;
  for (int i = 0; i < queryType.size(); i++) {
    if (i > 0) {
      keyShift[i] = keyShift[i-1];
      valueShift[i] = valueShift[i-1];
    }
    if (queryType[i] == "addToKey") {
      keyShift[i] += query[i][0];
    }
    if (queryType[i] == "addToValue") {
      valueShift[i] += query[i][0];
    }
    if (queryType[i] == "insert") {
      int key = query[i][0] - keyShift[i];
      map[key].first = query[i][1];
      map[key].second = i;
    }
    if (queryType[i] == "get") {
      int key = (long long) query[i][0] - keyShift[i];
      ans += map[key].first + valueShift[i] - valueShift[map[key].second];
    }
  }
  return ans;
}

/* GREAT JOB. THAT WAS SOME REAL GOOD PROBLEM SOLVING Pog! Hammered this out
 * in like 30-40 minutes and it worked first try!!! NO COMPILATION ERRORS WOO
 * HOOO. That was so smoov. 25 minutes actually. Noice!*/

