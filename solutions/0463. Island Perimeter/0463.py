# Time complexity: O(mn)
# Space complexity: O(1)
class Solution:
  def islandPerimeter(self,grid: List[List[int]]) -> int:
    ans = 0
    for i in range(len(grid)):
      for j in range(len(grid[0])):
        if grid[i][j] == 1:
          ans += (i == 0 or grid[i - 1][j] == 0)
          ans += (j == 0 or grid[i] [j - 1] == 0)

    return 2 * ans      