# Time complexity: O(m+nk)
# Space complexity: O(1)
class Solution:
  def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
    isAllowed = [False] * 26

    for char in allowed:
      isAllowed[ord(char) - ord('a')] = True

    ans = 0

    for word in words:
      isConsistent = True

      for char in word:
        if not isAllowed[ord(char) - ord('a')]:
          isConsistent = False
          break

      if isConsistent:
        ans += 1

    return ans