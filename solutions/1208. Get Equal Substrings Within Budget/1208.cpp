// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  int equalSubstring(string_view s, string_view t, int maxCost) {
    int j = 0;
    for (int i = 0; i < s.length(); ++i) {
      maxCost -= abs(s[i] - t[i]);
      if (maxCost < 0)
        maxCost += abs(s[j] - t[j++]);
    }

    return s.length() - j;
  }
};