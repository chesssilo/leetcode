# Time complexity: O(n)
# Space complexity: O(n)
class Solution:
  def getSmallestString(self, s: str, k: int) -> str:
    res = ""

    for c in s:
      minDistance = min(ord(c) - ord('a'), ord('z') - ord(c) + 1)

      if k >= minDistance:
        k -= minDistance
        res += 'a' if minDistance <= ord(c) - ord('a') else 'z'
      else:
        res += chr(ord(c) - k)
        k = 0

    return res