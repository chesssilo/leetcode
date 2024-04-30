# Time complexity: O(1)
# Space complexity: O(1)
class Solution:
  def minEnd(self, n: int, x: int) -> int:
    n -= 1
    temp = 1

    for _ in range(64):
      if temp & x == 0:
        x |= (n & 1) * temp
        n >>= 1
      temp <<= 1

    return x    
