# Time complexity: O(n)
# Space complexity: O(1)
class Solution:
  def minOperations(self, nums: List[int], k: int) -> int:
    count = 0
    
    for num in nums:
      if num < k:
        count += 1

    return count