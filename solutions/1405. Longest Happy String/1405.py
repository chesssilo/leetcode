# Time complexity: O(n)
# Space complexity: O(n)
class Solution:
  def longestDiverseString(
    self, a: int, b: int, c: int, 
    A: str = 'a', B: str = 'b', C: str = 'c'
  ) -> str:
    if a < b:
      return self.longestDiverseString(b, a, c, B, A, C)
    if b < c:
      return self.longestDiverseString(a, c, b, A, C, B)
    if b == 0:
      return A * min(a, 2)

    useA = min(a, 2)
    useB = 1 if (a - useA >= b) else 0

    return A  * useA + B * useB + \
           self.longestDiverseString(a - useA, b - useB, c, A, B, C)