# Time complexity: O(1)
# Space complexity: O(1)
class Solution:
  def hammingDistance(self, x: int, y: int) -> int:
    return bin(x ^ y).count('1')