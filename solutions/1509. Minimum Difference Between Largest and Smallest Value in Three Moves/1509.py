# Time complexity: O(sort)
# Space complexity: O(sort)
class Solution:
  def minDifference(self, nums: List[int]) -> int:
    n = len(nums)
    if n < 5:
      return 0

    ans = math.inf

    nums.sort()

    for i in range(4):
      ans = min(ans, nums[n - 4 + i] - nums[i])

    return ans