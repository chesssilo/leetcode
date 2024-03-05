# Time complexity: O(mn)
# Space complexity: O(1)
class Solution:
  def countSubmatrices(self, grid: List[List[int]], k: int) -> int:
    ans = 0

    for i in range(len(grid)):
      for j in range(len(grid[0])):
        if i > 0:
          grid[i][j] += grid[i - 1][j]
        if j > 0:
          grid[i][j] += grid[i][j - 1]
        if i > 0 and j > 0:
          grid[i][j] -= grid[i - 1][j - 1]

        if grid[i][j] <= k:
          ans += 1
        else:
          break

    return ans