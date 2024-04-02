// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  int lengthOfLastWord(string_view s) {
    int i = s.length() - 1;
    while (i >= 0 && s[i] == ' ')
      --i;

    const int lastIndex = i;
    while (i >= 0 && s[i] != ' ')
      --i;

    return lastIndex - i;
  }
};