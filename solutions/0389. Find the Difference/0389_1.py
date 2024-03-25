# Time complexity: O(n)
# Space complexity: O(1)
class Solution:
  def findTheDifference(self, s: str, t: str) -> str:
    sXors = chr(functools.reduce(lambda x, y: x ^ y, map(ord, s), 0))
    tXors = chr(functools.reduce(lambda x, y: x ^ y, map(ord, t), 0))

    return chr(ord(sXors) ^ ord(tXors))  