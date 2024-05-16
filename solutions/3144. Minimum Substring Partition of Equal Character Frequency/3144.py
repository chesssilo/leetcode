# Time complexity: O(n^2)
# Space complexity: O(n)
class Solution:
  def minimumSubstringsInPartition(self, s: str) -> int:
    n = len(s)
    dp = [0] * (n + 1)
    dp[0] = 0

    for i in range(1, n + 1):
      dp[i] = i
      count = {}
      for j in range(i, 0, -1):
        count[s[j - 1]] = count.get(s[j - 1], 0) + 1
        if len(set(count.values())) == 1:
          dp[i] = min(dp[i], 1 + dp[j - 1])

    return dp[n]