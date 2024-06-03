// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
 public:
  string clearStars(string s) {
    vector<int> pos[26];

    for (int i = 0; i < ssize(s); ++i) {
      if (s[i] == '*') {
        for (auto& p : pos) {
          if (!p.empty()) {
            s[p.back()] = '*';
            p.pop_back();
            break;
          }
        }
      } else {
        pos[s[i] - 'a'].push_back(i);
      }
    }
    s.erase(remove(s.begin(), s.end(), '*'), s.end());

    return s;
  }
};