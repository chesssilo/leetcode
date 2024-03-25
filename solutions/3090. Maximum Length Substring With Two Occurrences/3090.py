# Time complexity: O(n)
# Space complexity: O(1)
class Solution:
  def maximumLengthSubstring(self, s:str) -> int:
    maxLen = 0
    count = [0] * 26

    l = r = 0

    while r < len(s):
      count[ord(s[r]) - ord('a')] += 1

      while count[ord(s[r]) - ord('a')] > 2:
        count[ord(s[l]) - ord('a')] -= 1
        l += 1

      maxLen = max(maxLen, r - l + 1)
      r += 1

    return maxLen    