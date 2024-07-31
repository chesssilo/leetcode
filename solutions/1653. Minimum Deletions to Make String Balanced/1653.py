# Time complexity: O(n)
# Space complexity: O(1)
class Solution:
  def minimumDeletions(self, s: str) -> int:
    dp = 0
    countB = 0

    for c in s:
      if c == 'a':
        dp = min(dp + 1, countB)
      else:
        countB += 1

    return dp