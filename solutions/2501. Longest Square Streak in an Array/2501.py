# Time complexity: O(n)
# Space complexity: O(n)
class Solution:
  def longestSquareStreak(self, nums: List[int]) -> int:
    ans = 0
    uniqueNums = set(nums)

    for num in nums:
      currStreak = 0
      curr = num

      while curr in uniqueNums:
        currStreak += 1
        if curr * curr > 100_000:
          break
        curr *= curr

      ans = max(ans, currStreak)

    return ans if ans >= 2 else -1