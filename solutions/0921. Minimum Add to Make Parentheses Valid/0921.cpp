// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  int minAddToMakeValid(string_view s) {
    int l = 0;
    int r = 0;

    for (const char c : s)
      if (c == '(') {
        ++l;
      } else {
        if (l == 0)
          ++r;
        else
          --l;
      }

    return l + r;
  }
};