# Time complexity: O(n)
# Space complexity: O(1)
class Solution:
  def minSwaps(self, s: str) -> int:
    unmatched = 0

    for c in s:
      if c == '[':
        unmatched += 1
      elif unmatched > 0:
        unmatched -= 1

    return (unmatched + 1) // 2