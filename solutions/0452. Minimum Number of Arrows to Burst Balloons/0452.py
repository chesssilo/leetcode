# Time complexity: O(nlogn)
# Space complexity: O(1)
class Solution:
  def findMinArrowShots(self, points: List[List[int]]) -> int:
    ans = 0
    arrowX = -math.inf

    for point in sorted(points, key=lambda x: x[1]):
      if point[0] > arrowX:
        arrowX = point[1]
        ans += 1

    return ans