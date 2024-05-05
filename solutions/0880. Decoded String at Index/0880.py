# Time complexity: O(n)
# Space complexity: O(1)
class Solution:
  def decodeAtIndex(self, s: str, k: int) -> str:
    length = 0

    for c in s:
      if c.isdigit():
        length *= int(c)
      else:
        length += 1

    for c in reversed(s):
      k %= length
      if k == 0 and c.isalpha():
        return c
      if c.isdigit():
        length //= int(c)
      else:
        length -= 1        