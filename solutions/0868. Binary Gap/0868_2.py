# Time Complexity: O(log⁡N).
# Space Complexity: O(1).
class Solution:
  def binaryGap(self, n: int) -> int:
    last = None
    ans = 0
    for i in range(32):
      if (n >> i) & 1:
        if last is not None:
          ans = max(ans, i - last)
        last = i
    return ans