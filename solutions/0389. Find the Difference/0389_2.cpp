// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  char findTheDifference(string_view s, string_view t) {
    int count[26] = {0};

    for (const char c : s)
      ++count[c - 'a'];

    for (const char c : t) {
      if (count[c - 'a'] == 0)
        return c;
      --count[c - 'a'];
    }

    throw "No difference found";
  }
};