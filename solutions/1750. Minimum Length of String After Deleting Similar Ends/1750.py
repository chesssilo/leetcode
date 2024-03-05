# Time complexity: O(n)
# Space complexity: O(1)
class Solution:
  def minimumLength(self, s: str) -> int:
    left = 0
    right = len(s) - 1

    while left < right and s[left] == s[right]:
      c = s[left]
      while left <= right and s[left] == c:
        left += 1
      while left < right and s[right] == c:
        right -= 1

    return right - left + 1