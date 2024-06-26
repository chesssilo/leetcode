# Time complexity: O(n^2)
# Space complexity: O(n)
class Solution:
  def longestArtithSeqlength(self, nums: List[int]) -> int:
    n = len(nums)
    ans = 0
    dp = [[0] * 1001 for _ in range(n)]

    for i in range(n):
      for j in range(i):
        k = nums[i] - nums[j] + 500
        dp[i][k] = max(2, dp[j][k] + 1)
        ans = max(ans, dp[i][k])

    return ans