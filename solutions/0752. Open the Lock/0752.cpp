// Time complexity: O(10^4)
// Space complexity: O(10^4)
class Solution {
 public:
  int openLock(const vector<string>& deadends, string_view target) {
    unordered_set<string> seen{deadends.begin(), deadends.end()};

    if (seen.count("0000"))
      return -1;
    if (target == "0000")
      return 0;

    int ans = 0;
    queue<string> q{{"0000"}};

    while (!q.empty()) {
      ++ans;
      for (int sz = q.size(); sz > 0; --sz) {
        string word = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
          const char cache = word[i];
          word[i] = word[i] == '9' ? '0' : word[i] + 1;
          if (word == target)
            return ans;
          if (!seen.count(word)) {
            q.push(word);
            seen.insert(word);
          }
          word[i] = cache;
          word[i] = word[i] == '0' ? '9' : word[i] - 1;
          if (word == target)
            return ans;
          if (!seen.count(word)) {
            q.push(word);
            seen.insert(word);
          }
          word[i] = cache;
        }
      }
    }

    return -1;
  }
};