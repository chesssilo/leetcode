# Time complexity: O(n)
# Space complexity: O(1)
class Solution:
  def appendCharacters(self, s: str, t: str) -> int:
    i = 0
    for c in s:
      if i < len(t) and c == t[i]:
        i += 1
        if i == len(t):
          return 0

    return len(t) - i