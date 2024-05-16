# Time complexity: O(n)
# Space complexity: O(1)
class Solution:
  def findPermutationDifference(self, s: str, t: str) -> int:
    ans = 0
    indices = [0] * 26

    for i, ch in enumerate(t):
      indices[ord(ch) - ord('a')] = i

    for i, ch in enumerate(s):
      ans += abs(i - indices[ord(ch) - ord('a')])

    return ans