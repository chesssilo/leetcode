# Time complexity: O(mn)
# Space complexity: O(m+n)
class Solution:
  def numberOfRightTriangles(self, grid: List[List[int]]) -> int:
    n = len(grid)
    m = len(grid[0])
    dp1 = [0] * n
    dp2 = [0] * m

    for i in range(n):
      for j in range(m):
        if grid[i][j] == 1:
          dp1[i] += 1
          dp2[j] += 1

    ans = 0
    for i in range(n):
      for j in range(m):
        if grid[i][j] == 1:
          ans += (dp1[i] - 1) * (dp2[j] - 1)

    return ans