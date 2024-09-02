# Time complexity: O(nk)
# Space complexity: O(k)
class Solution:
  def canPartition(self, nums: List[int]) -> bool:
    summ = sum(nums)
    if summ % 2 == 1:
      return False
    return self._knapsack(nums, summ // 2)

  def _knapsack(self, nums: List[int], subsetSum: int) -> bool:
    dp = [False] * (subsetSum + 1)
    dp[0] = True

    for num in nums:
      for i in range(subsetSum, num - 1, -1):
        dp[i] = dp[i] or dp[i - num]

    return dp[subsetSum]