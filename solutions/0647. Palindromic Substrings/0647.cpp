// Time complexity: O(n^2)
// Space complexity: O(1)
class Solution {
public:
  int countSubstrings(string_view s) {
    int ans = 0;

    for (int i = 0; i < s.length(); ++i) {
      ans += extendPalindromes(s, i, i);
      ans += extendPalindromes(s, i, i + 1);
    }

    return ans;
    }
private:
  int extendPalindromes(string_view s, int left, int right) {
    int count = 0;

    while (left >= 0 && right < s.length() && s[left] == s[right]) {
      ++count;
      --left;
      ++right;
    }

    return count;
  }    
};