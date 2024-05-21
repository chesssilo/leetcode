# Time complexity: O(n)
# Space complexity: O(1)
class Solution:
  def subsetXORSum(self, nums: List[int]) -> int:
    return functools.reduce(operator.or_, nums) << len(nums) - 1