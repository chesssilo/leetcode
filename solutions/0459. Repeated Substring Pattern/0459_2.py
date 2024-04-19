# Time complexity: O(n^2)
# Space complexity: O(1)
class Solution:
  def repeatedSubstringPattern(self, s: str) -> bool:
    for period in range(1, len(s)//2 + 1):
      if len(s) % period == 0:
        good = True
        for i in range(period, len(s)):
          if s[i] != s[i - period]:
            good = False
            break
        if good:
          return True

    return False      