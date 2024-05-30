# Time complexity: O(n)
# Space complexity: O(1)
class Solution:
  def numSteps(self, s: str) -> int:
    ans = 0
    chars = [c for c in s]

    while chars[-1] == '0':
      chars.pop()
      ans += 1

    if ''.join(chars) == '1':
      return ans

    return ans + 1 + sum(1 if c == '1' else 2 for c in chars)