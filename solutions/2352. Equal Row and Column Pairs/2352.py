# Time complexity: O(n^3)
# Space complexity: O(1)
class Solution:
  def equalPairs(self, grid: List[List[int]]) -> int:
    n = len(grid)
    ans = 0

    for i in range(n):
      for j in range(n):
        k = 0
        while k < n:
          if grid[i][k] != grid[k][j]:
            break
          k += 1
        if k == n:
          ans += 1

    return ans        