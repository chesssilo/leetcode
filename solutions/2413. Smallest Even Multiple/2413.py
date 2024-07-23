# Time complexity: O(1)
# Space complexity: O(1)
class Solution:
  def smallestEvenMultiple(self, n: int) -> int:
    return n * (n % 2 + 1)