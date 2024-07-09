# Time complexity: O(n)
# Space complexity: O(1)
class Solution:
  def findTheWinner(self, n: int, k: int) -> int:
    return reduce(lambda ans, i: (ans + k) % i, range(2, n + 1), 0) + 1