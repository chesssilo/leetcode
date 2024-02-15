# Time complexity: O(sort)
# Space complexity: O(sort)
class Solution:
  def largestPerimeter(self, nums: List[int]) -> int:
    nums.sort()
    prefix = 0
    ans = -1

    for num in nums:
      if num < prefix:
        ans = num + prefix

      prefix += num

    return ans   