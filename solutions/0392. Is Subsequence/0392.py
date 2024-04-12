# Time complexity: O(n)
# Space complexity: O(1)
class Solution:
  def isSubsequence(self, s: str, t: str) -> bool:
    i, j = 0, 0
    while i < len(s) and j < len(t):
      if s[i] == t[j]:
        i += 1
      j += 1
    
    return i == len(s)