# Time complexity: O(sort)
# Space complexity: O(sort)
class Solution:
  def maxCoins(self, piles: List[int]) -> int:
    return sum(sorted(piles)[len(piles) // 3::2])