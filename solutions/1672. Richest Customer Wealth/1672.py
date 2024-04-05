# Time complexity: O(mn)
# Space complexity: O(1)
class Solution:
  def maxmumWealth(self, accounts: List[List[int]]) -> int:
    return max(map(sum, accounts))