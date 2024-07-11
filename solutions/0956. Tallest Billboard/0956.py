# Time complexity: O(nm)
# Space complexity: O(m)
class Solution:
  def tallestBillboard(self, rods: List[int]) -> int:
    dp = defaultdict(int)
    dp[0] = 0

    for h in rods:
      prev = dict(dp)
      for diff in prev:
        dp[diff] = max(dp[diff], prev[diff])
        dp[diff + h] = max(dp[diff + h], prev[diff])
        dp[abs(diff - h)] = max(dp[abs(diff - h)], prev[diff] + min(diff, h))

    return dp[0]