# Time complexity: O(1)
# Space complexity: O(1)
class Solution:
  def findComplement(self, num: int) -> int:
    i = 1

    while i <= num:
      num ^= i
      i <<= 1

    return num