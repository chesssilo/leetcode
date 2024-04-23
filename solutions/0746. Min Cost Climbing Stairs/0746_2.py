# Time complexity: O(n)
# Space complexity: O(1)
class Solution:
  def minCostClimbingStairs(self, cost: List[int]) -> int:
    prev = cost[0]
    curr = cost[1]

    for i in range(2,len(cost)):
      next = cost[i] + min(prev, curr)
      prev, curr = curr, next

    return min(prev, curr)