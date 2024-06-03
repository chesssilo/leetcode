// Time complexity: O(n^2)
// Space complexity: O(n)
class Solution {
 public:
  int minimumDifference(const vector<int>& nums, int k) {
    int ans = INT_MAX;
    int dp[1000001] = {};

    for (int i = 0; i < ssize(nums); ++i)
      for (int j = i, val = nums[i]; j < ssize(nums); ++j) {
        val &= nums[j];
        ans = min(ans, abs(k - val));
        if (k - val >= ans || val <= dp[j])
          break;
        dp[j] = val;
      }

    return ans;
  }
};