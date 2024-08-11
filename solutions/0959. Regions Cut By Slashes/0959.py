# Time complexity: O(n^2)
# Space complexity: O(n^2)
class Solution:
  def regionsBySlashes(self, grid: List[int]) -> int:
    n = len(grid)
    g = [[0] * (n * 3) for _ in range(n * 3)]

    for i in range(n):
      for j in range(n):
        if grid[i][j] == '/':
          g[i * 3][j * 3 + 2] = 1
          g[i * 3 + 1][j * 3 + 1] = 1
          g[i * 3 + 2][j * 3] = 1
        elif grid[i][j] == '\\':
          g[i * 3][j * 3] = 1
          g[i * 3 + 1][j * 3 + 1] = 1
          g[i * 3 + 2][j * 3 + 2] = 1

    def dfs(i, j):
      if i < 0 or i >= len(g) or j < 0 or j >= len(g[0]):
        return
      if g[i][j] != 0:
        return

      g[i][j] = 2
      dfs(i + 1, j)
      dfs(i - 1, j)
      dfs(i, j + 1)
      dfs(i, j - 1)

    ans = 0
    for i in range(n * 3):
      for j in range(n * 3):
        if g[i][j] == 0:
          dfs(i, j)
          ans += 1

    return ans