# Time complexity: O(one*zero*limit)
# Space complexity: O(one*zero)
class Solution:
  def numberOfStableArrays(self, zero: int, one: int, limit: int) -> int:
    kMod = 1_000_000_007
    dp = [[[-1 for _ in range(2)] for _ in range(zero + 1)] 
          for _ in range(one + 1)]

    def dfs(zero: int, one: int, limit: int, ms: bool) -> int:
      if one == 0 and zero == 0:
        return 1
      
      res = 0

      if dp[one][zero][ms] != -1:
        return dp[one][zero][ms]
      
      if ms:
        for i in range(1, min(one, limit) + 1):
          res += dfs(zero, one - i, limit, False) % kMod
      else:
        for i in range(1, min(zero, limit) + 1):
          res += dfs(zero - i, one, limit, True) % kMod

      dp[one][zero][ms] = res % kMod

      return dp[one][zero][ms]
    
    a = dfs(zero, one, limit, True) % kMod
    b = dfs(zero, one, limit, False) % kMod

    return (a + b) % kMod