# Time complexity: O(n^2)
# Space complexity: O(1)
class Solution:
  def largestSquareArea(self, bottomLeft: List[List[int]], topRight: List[List[int]]) -> int:
    maxArea = 0

    for i in range(len(bottomLeft)):
      for j in range(i + 1, len(bottomLeft)):
        x1 = max(bottomLeft[i][0], bottomLeft[j][0])
        y1 = max(bottomLeft[i][1], bottomLeft[j][1])
        x2 = min(topRight[i][0], topRight[j][0])
        y2 = min(topRight[i][1], topRight[j][1])

        if x1 < x2 and y1 < y2:
          side = min(x2 - x1, y2 - y1)
          maxArea = max(maxArea, side * side)

    return maxArea