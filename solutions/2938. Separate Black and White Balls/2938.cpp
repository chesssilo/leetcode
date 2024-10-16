// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  long long minimumSteps(string_view s) {
    long ans = 0;
    int ones = 0;

    for (const char c : s)
      if (c == '1')
        ++ones;
      else
        ans += ones;

    return ans;
  }
};