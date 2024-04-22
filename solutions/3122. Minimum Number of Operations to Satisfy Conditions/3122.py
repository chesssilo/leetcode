# Time complexity: O(rows*cols)
# Space complexity: O(rows*cols)
class Solution:
  def minimumOperations(self, grid: List[List[int]]) -> int:
    rows = len(grid)
    cols = len(grid[0])

    count = [[0] * 10 for _ in range(cols)]

    for i in range(cols):
      for j in range(rows):
        count[i][grid[j][i]] += 1

    dp = [[-1] * 11 for _ in range(1001)]

    minimumOps = self.calculateMinimumOperations(0, 10, rows, cols, count, dp)

    return minimumOps
  
  def calculateMinimumOperations(self, index, prev, rows, cols, count, dp):
    if index >= cols:
      return 0
    if dp[index][prev] != -1:
      return dp[index][prev]
    
    ans = float('inf')

    for i in range(10):
      if i != prev:
        ans = min(ans, rows - count[index][i] + 
                  self.calculateMinimumOperations(index + 1, 
                                                  i, rows, cols, count, dp))

    dp[index][prev] = ans

    return ans