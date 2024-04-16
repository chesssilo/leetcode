# Time complexity: O(sort)
# Space complexity: O(1)
class Solution:
  def minRectanglesToCoverPoints(self, points: List[List[int]], w: int) -> int:
    points.sort()

    ans = 0
    idx = -1

    for point in points:
      if point[0] > idx:
        ans += 1
        idx = point[0] + w

    return ans    