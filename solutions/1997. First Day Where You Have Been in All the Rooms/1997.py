# Time complexity: O(n)
# Space complexity: O(n)
class Solution:
  def firstDayBeenInAllRooms(self, nextVisit: List[int]) -> int:
    kMod = 1_000_000_007
    n = len(nextVisit)
    dp = [0] * n

    for i in range(1, n):
      dp[i] = (2 * dp[i - 1] - dp[nextVisit[i - 1]] + 2) % kMod

    return dp[-1]