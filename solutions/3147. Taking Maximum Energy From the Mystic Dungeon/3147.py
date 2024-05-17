# Time complexity: O(n)
# Space complexity: O(n)
class Solution:
  def maximumEnergy(self, energy: List[int], k: int) -> int:
    dp = energy[:]
    for i in reversed(range(len(energy) - k)):
      dp[i] += dp[i + k]

    return max(dp)