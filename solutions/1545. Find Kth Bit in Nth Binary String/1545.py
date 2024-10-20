# Time complexity: O(1)
# Space complexity: O(1)
class Solution:
  def findKthBit(self, n: int, k: int) -> str:
    positionInSection = k & -k
    isInInvertedPart = ((k // positionInSection) >> 1 & 1) == 1

    originalBitIsOne = (k & 1) == 0

    if isInInvertedPart:
      return "0" if originalBitIsOne else "1"
    else:
      return "1" if originalBitIsOne else "0"