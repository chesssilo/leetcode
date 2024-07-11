# Time complexity: O(n^2)
# Space complexity: O(n)
class Solution:
  def minCostConnectPoints(self, points: List[int]) -> int:
    dist = [math.inf] * len(points)
    ans = 0

    for i in range(len(points) - 1):
      for j in range(i + 1, len(points)):
        dist[j] = min(dist[j], abs(points[i][0] - points[j][0]) +
                               abs(points[i][1] - points[j][1]))
        if dist[j] < dist[i + 1]:
          points[j], points[i + 1] = points[i + 1], points[j]
          dist[j], dist[i + 1] = dist[i + 1], dist[j]
      ans += dist[i + 1]

    return ans