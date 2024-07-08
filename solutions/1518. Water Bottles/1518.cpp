// Time complexity: O(1)
// Space complexity: O(1)
class Solution {
 public:
  int numWaterBottles(int numBottles, int numExchange) {
    return numBottles + (numBottles - 1) / (numExchange - 1);
  }
};