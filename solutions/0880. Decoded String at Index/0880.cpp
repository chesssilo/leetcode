// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  string decodeAtIndex(string_view s, int k) {
    long length = 0;

    for (const char c : s)
      if (isdigit(c))
        length *= c - '0';
      else
        ++length;

    for (int i = s.length() - 1; i >= 0; --i) {
      k %= length;
      if (k == 0 && isalpha(s[i]))
        return string(1, s[i]);
      if (isdigit(s[i]))
        length /= s[i] - '0';
      else
        --length;
    }

    throw;
  }
};