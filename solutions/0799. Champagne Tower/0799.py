# Time complexity: O(n^2)
# Space complexity: O(n)
class Solution:
  def champagneTower(
    self, poured: int, query_row: int, query_glass: int
  ) -> float:
    dp = [0.0] * (query_row + 1)
    dp[0] = poured

    for i in range(query_row):
      newDp = [0.0] * (query_row + 1)
      for j in range(i + 1):
        if dp[j] > 1:
          overflow = (dp[j] - 1) / 2.0
          newDp[j] += overflow
          newDp[j + 1] += overflow
      dp = newDp

    return min(1.0, dp[query_glass])