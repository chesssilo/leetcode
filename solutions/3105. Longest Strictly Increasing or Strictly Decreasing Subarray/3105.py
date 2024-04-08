# Time complexity: O(n)
# Space complexity: O(1)
class Solution:
  def longestMonotonicSubarray(self, nums: List[int]) -> int:
    ans = 1
    incLength = 1
    decLength = 1

    for i in range(1, len(nums)):
      if nums[i] > nums[i - 1]:
        incLength += 1
        decLength = 1
      elif nums[i] < nums[i - 1]:
        decLength += 1
        incLength = 1
      else:
        decLength = 1
        incLength = 1
      ans = max(ans, max(incLength, decLength))

    return ans    
