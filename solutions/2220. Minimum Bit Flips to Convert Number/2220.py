# Time complexity: O(logn)
# Space complexity: O(1)
class Solution:
  def minBitFlips(self, start: int, goal: int) -> int:
    return (start ^ goal).bit_count()