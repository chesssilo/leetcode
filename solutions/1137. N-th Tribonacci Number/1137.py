# Time complexity: O(n)
# Space complexity: O(1)
class Solution:
  def tribonacci(self, n: int) -> int:
    if n <= 2:
      return 0 if n == 0 else 1
    
    a, b, c = 0, 1, 1
    for i in range(3, n + 1):
      t = a + b + c
      a, b, c = b, c, t

    return c   