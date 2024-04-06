# Time complexity: O(n)
# Space complexity: O(n)
class Solution:
  def makeGood(self, s: str) -> str:
    ans = []
    for c in s:
      if ans and self.isBadPair(ans[-1], c):
        ans.pop()
      else:
        ans.append(c)

    return ''.join(ans)

  def isBadPair(self, a: str, b: str) -> bool:
    return a != b and a.lower() == b.lower()