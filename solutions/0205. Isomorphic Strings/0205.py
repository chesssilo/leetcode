# Time complexity: O(n)
# Space complexity: O(1)
class Solution:
  def isIsomorphic(self, s: str, t: str) -> bool:
    mapS = [0] * 128
    mapT = [0] * 128

    for i in range(len(s)):
      if mapS[ord(s[i])] != mapT[ord(t[i])]:
        return False
      mapS[ord(s[i])] = i + 1
      mapT[ord(t[i])] = i + 1

    return True