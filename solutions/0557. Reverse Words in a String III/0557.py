# Time complexity: O(n)
# Space complexity: O(1)
class Solution:
  def reverseWords(self, s: str) -> str:
    s = list(s)
    i = 0
    j = 0
    n = len(s)

    while i < n:
      while i < j or (i < n and s[i] == ' '):
        i += 1
      while j < i or (j < n and s[j] != ' '):
        j += 1
      s[i:j] = reversed(s[i:j])

    return ''.join(s)