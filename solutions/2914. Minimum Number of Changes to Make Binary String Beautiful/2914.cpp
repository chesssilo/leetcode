// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  int minChanges(string_view s) {
    int ans = 0;

    for (int i = 0; i < s.length(); i += 2)
      if (s[i] != s[i + 1])
        ++ans;

    return ans;
  }
};