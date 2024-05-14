# Time Complexity: O(log⁡n)
# Space Complexity: O(1)
class Solution:
  def binaryGap(self, n: int) -> int:
    ans = 0
    d = -32

    while n:
      if n & 1:
        ans = max(ans, d)
        d = 0
      n //= 2
      d += 1

    return ans