# Time complexity: O(logk)
# Space complexity: O(1)
class Solution:
  def kthGrammar(self, n: int, k: int) -> int:
    count = bin(k - 1).count('1')
    return 0 if count % 2 == 0 else 1