# Time complexity: O(n)
# Space complexity: O(n)
class Solution:
  def clearStars(self, s: str) -> str:
    pos = {chr(i + ord('a')): [] for i in range(26)}
    s = list(s)

    for i , c in enumerate(s):
      if c == '*':
        for p in pos.values():
          if p:
            s[p.pop()] = '*'
            break
      else:
        pos[c].append(i)

    return ''.join(c for c in s if c != '*')