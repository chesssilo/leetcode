// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
  int minimumLength(string_view s) {
    int left = 0;
    int right = s.length() - 1;

    while (left < right && s[left] == s[right]) {
      char const c = s[left];

      while (left <= right && s[left] == c)
        ++left;

      while (left < right && s[right] == c)
        --right;  
      }

    return right - left + 1;
  }
};