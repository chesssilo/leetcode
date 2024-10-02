# Time complexity: O(n)
# Space complexity: O(1)
class Solution:
  def longestSubarray(self, nums: List[int]) -> int:
    l = 0
    zeros = 0

    for num in nums:
      if num == 0:
        zeros += 1
      if zeros > 1:
        if nums[l] == 0:
          zeros -= 1
        l += 1

    return len(nums) - l - 1