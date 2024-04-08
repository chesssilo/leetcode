# Time complexity: O(n)
# Space complexity: O(1)
class Solution:
  def checkPossibility(self, nums: List[int]) -> bool:
    count = 0
    prev = float('-inf')

    for i in range(len(nums)):
      if nums[i] < prev:
        count += 1
        if count > 1:
          return False
        if i > 1 and nums[i - 2] > nums[i]:
          continue
      prev = nums[i]

    return True    