# Time complexity: O(1)
# Space complexity: O(1)
class Solution:
  def minOperations(self, k: int) -> int:
    a = int(math.sqrt(k))
    return a + (k - 1) // a - 1