# Time complexity: O(sort)
# Space complexity: O(sort)
class Solution:
  def minOperationsToMakeMedianK(self, nums: List[int], k: int) -> int:
    ans = 0

    nums.sort()
    for i in range(len(nums) // 2 + 1):
      ans += max(0, nums[i] - k)
    for i in range(len(nums) // 2, len(nums)):
      ans += max(0, k - nums[i])

    return ans