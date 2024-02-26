# Time complexity: O(n)
# Space complexity: O(1)
class Solution:
  def isPossibleToSplit(self, nums: List[int]) -> bool:
    count = [0] * 101

    for num in nums:
      count[num] += 1
      if count[num] > 2:
        return False

    return True  