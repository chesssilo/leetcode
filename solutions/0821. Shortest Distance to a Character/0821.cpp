// Time Complexity: O(N)
// Space Complexity: O(N)
class Solution {
public:
  vector<int> shortestToChar(const string &s, char c) {
    const int INF =(int)s.size();
    vector<int> res(s.size(), INF);
    int dist = INF;
    for (int i = 0; i < (int)s.size(); i++) {
      if (s[i] == c) {
        dist = 0;
      } else {
        dist++;
      }
      res[i] = dist;
    }
    dist = INF;
    for (int i = (int)s.size() - 1; i >= 0; i--) {
      if (s[i] == c) {
        dist = 0;
      } else {
        dist++;
      }
      res[i] = min(res[i], dist);
    }
    return res;
  }
};
