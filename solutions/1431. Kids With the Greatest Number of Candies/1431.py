# Time complexity: O(n)
# Space complexity: O(n)
class Solution:
  def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
    maxCandy = max(candies)
    return [candy + extraCandies >= maxCandy for candy in candies]