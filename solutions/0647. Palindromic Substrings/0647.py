# Time complexity: O(n^2)
# Space complexity: O(1)
class Solution:
  def countSubstrings(self, s: str) -> int:
    ans = 0

    for i in range(len(s)):
      ans += self.extendPalindromes(s, i, i)
      ans += self.extendPalindromes(s, i, i + 1)

    return ans

  def extendPalindromes(self, s: str, left: int, right: int) -> int:
    count = 0

    while left >= 0 and right < len(s) and s[left] == s[rigth]:
      count += 1
      left -= 1
      right += 1

    return count