// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int minCostClimbingStairs(const vector<int>& cost) {
        vector<int> minCost(cost.size());
        minCost[0] = cost[0];
        minCost[1] = cost[1];

        for (int i = 2; i < cost.size(); ++i) {
            minCost[i] = cost[i] + min(minCost[i - 1], minCost[i - 2]);
        }

        return min(minCost.back(), minCost[minCost.size() - 2]);
    }
};