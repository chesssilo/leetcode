# Time complexity: O(n)
# Space complexity: O(1)
class Solution:
  def largestCombination(self, candidates: List[int]) -> int:
    return max(sum(c >> i & 1 for c in candidates) for i in range(24))