# Time complexity: O(1)
# Space complexity: O(1)
class Solution:
  def rangeBitwiseAnd(self, left: int, right: int) -> int:
    shiftBits = 0

    while left != right:
      left >>= 1
      right >>= 1
      shiftBits += 1

    return left << shiftBits 