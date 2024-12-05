// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  bool canMakeSubsequence(string_view str1, string_view str2) {
    int i = 0;

    for (const char c : str1)
      if (c == str2[i] || ('a' + ((c - 'a' + 1) % 26)) == str2[i])
        if (++i == str2.length())
          return true;

    return false;
  }
};