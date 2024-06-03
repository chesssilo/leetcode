# Time complexity: O(n)
# Space complexity: O(1)
class Solution:
  def minimumChairs(self, s: str) -> int:
    return max(accumulate([1 if c == "E" else -1 for c in s]))