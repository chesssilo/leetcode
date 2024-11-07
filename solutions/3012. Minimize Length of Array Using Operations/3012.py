# Time complexity: O(n)
# Space complexity: O(1)
class Solution:
  def minimumArrayLength(self, nums: List[int]) -> int:
    minNum = min(nums)
    
    if any(num % minNum > 0 for num in nums):
      return 1

    return (nums.count(minNum) + 1) // 2