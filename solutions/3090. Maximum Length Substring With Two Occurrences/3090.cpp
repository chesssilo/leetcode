// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  int maximumLengthSubstring(string_view s) {
    int maxLen = 0;
    int count[26] = {0};

    for (int l = 0, r = 0; r < s.length(); ++r) {
      ++count[s[r] - 'a'];

      while (count[s[r] - 'a'] > 2) {
        --count[s[l] - 'a'];
        ++l;
      }

      maxLen = max(maxLen, r - l + 1);
    }

    return maxLen;
  }
};