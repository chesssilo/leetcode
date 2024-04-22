# Time complexity: O(n)
# Space complexity: O(1)
class Solution:
  def numberOfSpecialChars(self, word: str) -> int:
    lowercase = [False] * 26
    uppercase = [False] * 26
    ans = 0

    for c in word:
      if c.islower():
        lowercase[ord(c) - ord('a')] = True
      else:
        uppercase[ord(c) - ord('A')] = True

    for i in range(26):
      if lowercase[i] and uppercase[i]:
        ans += 1

    return ans       