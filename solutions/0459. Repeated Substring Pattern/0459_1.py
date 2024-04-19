# Time complexity: O(n^2)
# Space complexity: O(n)
class Solution:
  def repeatedSubstringPattern(self, s: str) -> bool:
    return s in (s + s)[1: -1]