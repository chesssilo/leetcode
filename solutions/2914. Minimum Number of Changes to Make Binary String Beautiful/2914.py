# Time complexity: O(n)
# Space complexity: O(1)
class Solution:
  def minChanges(self, s: str) -> int:
    return sum(a != b for a, b in zip(s[::2], s[1::2]))