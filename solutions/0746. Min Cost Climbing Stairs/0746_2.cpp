// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  int minCostClimbingStairs(const vector<int>& cost) {
    int prev = cost[0];
    int curr = cost[1];

    for (int i = 2; i < cost.size(); ++i) {
      int next = cost[i] + min(prev, curr);
      prev = curr;
      curr = next;
    }

    return min(prev, curr);
  }
};