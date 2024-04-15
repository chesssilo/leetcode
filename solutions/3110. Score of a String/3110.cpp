// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  int scoreOfString(string_view s) {
    int ans = 0;
    for (int i = 1; i < s.length(); ++i)
      ans += abs(s[i] - s[i - 1]);

    return ans;
  }
};