// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
 public:
  int findMaxK(const vector<int>& nums) {
    int ans = -1;
    unordered_set<int> seen;

    for (const int num : nums)
      if (seen.count(-num))
        ans = max(ans, abs(num));
      else
        seen.insert(num);

    return ans;
  }
};