# Time complexity: O(mn)
# Space complexity: O(mn)
class Solution:
  def countSubIslands(
    self,
    grid1: List[List[int]],
    grid2: List[List[int]]
  ) -> int:
    def dfs(i: int, j: int) -> int:
      if i < 0 or i == len(grid2) or j < 0 or j == len(grid2[0]):
        return 1
      if grid2[i][j] != 1:
        return 1

      grid2[i][j] = 2

      return (dfs(i + 1, j) & dfs(i - 1, j) & 
              dfs(i, j + 1) & dfs(i, j - 1) & grid1[i][j])

    ans = 0

    for i in range(len(grid2)):
      for j in range(len(grid2[0])):
        if grid2[i][j] == 1:
          ans += dfs(i, j)

    return ans