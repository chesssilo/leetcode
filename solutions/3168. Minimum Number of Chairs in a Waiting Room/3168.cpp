// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  int minimumChairs(string_view s) {
    int ans = 0;
    int count = 0;

    for (const char c : s) {
      count += (c == 'E') ? 1 : -1;
      ans = max(ans, count);
    }

    return ans;
  }
};