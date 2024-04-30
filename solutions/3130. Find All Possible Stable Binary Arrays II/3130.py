# Time complexity: O(one*zero)
# Space complexity: O(one*zero)
class Solution:
  def numberOfStableArrays(self, zero: int, one: int, limit: int) -> int:
    kMod = 1_000_000_007
    dp = [[[0 for _ in range(2)] for _ in range(one + 1)] 
          for _ in range(zero + 1)]

    for i in range(zero + 1):
      for j in range(one + 1):
        dp[i][j][0] = 0
        dp[i][j][1] = 0

        if i == 0 or j == 0:
          if 0 < i and i <= limit:
            dp[i][j][0] = 1
          if 0 < j and j <= limit:
            dp[i][j][1] = 1
          continue

        if i > 0:
          dp[i][j][0] = (dp[i - 1][j][0] + dp[i - 1][j][1]) % kMod
        if i - limit > 0:
          dp[i][j][0] = (dp[i][j][0] + kMod - dp[i - 1 - limit][j][1]) % kMod 
        if j > 0:
          dp[i][j][1] = (dp[i][j - 1][0] + dp[i][j - 1][1]) % kMod
        if j - limit > 0:
          dp[i][j][1] = (dp[i][j][1] + kMod - dp[i][j - 1 - limit][0]) % kMod

    dp[zero][one][0] = (dp[zero][one][0] + dp[zero][one][1]) % kMod

    return dp[zero][one][0]