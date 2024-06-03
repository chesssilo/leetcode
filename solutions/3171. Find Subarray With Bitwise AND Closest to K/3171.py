# Time complexity: O(n^2)
# Space complexity: O(n)
class Solution:
  def minimumDifference(self, nums: List[int], k: int) -> int:
    ans = float('inf')
    dp = [0] * 1000001

    for i in range(len(nums)):
      val = nums[i]
      for j in range(i, len(nums)):
        val &= nums[j]
        ans = min(ans, abs(k - val))
        if k - val >= ans or val <= dp[j]:
          break
        dp[j] = val

    return ans