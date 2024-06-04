// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  int appendCharacters(string_view s, string_view t) {
    int i = 0;

    for (const char c : s)
      if (c == t[i])
        if (++i == t.length())
          return 0;

    return t.length() - i;
  }
};