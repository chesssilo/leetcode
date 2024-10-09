// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  int minSwaps(string_view s) {
    int unmatched = 0;

    for (const char c : s)
      if (c == '[')
        ++unmatched;
      else if (unmatched > 0)
        --unmatched;

    return (unmatched + 1) / 2;
  }
};