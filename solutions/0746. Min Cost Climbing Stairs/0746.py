# Time complexity: O(n)
# Space complexity: O(1)
class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        prev = cost[0]
        cur = cost[1]

        for i in range(2,len(cost)):
            next = cost[i] + min(prev, cur)
            prev, cur = cur, next

        return min(prev, cur)