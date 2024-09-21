# Time complexity: O(n)
# Space complexity: O(n)
class Solution:
  def shortestPalindrome(self, s: str) -> str:
    hashBase = 29
    kMod = 1_000_000_007
    forwHash = 0
    revHash = 0
    powVal = 1
    index = -1

    for i, currChar in enumerate(s):
      forwHash = (forwHash * hashBase + (ord(currChar) - ord('a') + 1)) % kMod
      revHash = (revHash + (ord(currChar) -  ord('a') + 1) * powVal) % kMod
      powVal = (powVal * hashBase) % kMod

      if forwHash == revHash:
        index = i

    suffix = s[index + 1 :]
    revSuffix = suffix[::-1]

    return revSuffix + s