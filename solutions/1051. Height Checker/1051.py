# Time complexity: O(sort)
# Space complexity: O(n)
class Solution:
  def heightChecker(self, heights: List[int]) -> int:
    expected = sorted(heights)
    ans = sum(h != e for h, e in zip(heights, expected))

    return ans