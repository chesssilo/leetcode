# Time complexity: O(sort)
# Space complexity: O(n)
class Solution:
  def jobScheduling(
    self, startTime: List[int], endTime: List[int], profit: List[int]
  ) -> int:
    jobs =sorted(zip(endTime, startTime, profit))

    numberOfJobs = len(profit)

    dp = [0] * (numberOfJobs + 1)

    for i, (_, currentStartTime, currentProfit) in enumerate(jobs):
      index = bisect_right(jobs, currentStartTime, hi=i, key=lambda x: x[0])
      dp[i + 1] = max(dp[i], dp[index] + currentProfit)

    return dp[numberOfJobs]