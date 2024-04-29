# Time complexity: O(1)
# Space complexity: O(1)
class Solution:
  def canMakeSquare(self, grid: List[List[str]]) -> bool:
    for i in range(len(grid) - 1):
      for j in range(len(grid[0]) - 1):
        b, w = 0, 0
        for u, v in [(i, j), (i + 1, j), (i, j + 1), (i + 1, j + 1)]:
          b += int(grid[u][v] == 'B')
          w += int(grid[u][v] == 'W')
        if b >= 3 or w >= 3:
          return True
        
      return False