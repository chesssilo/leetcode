// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  int maxBottlesDrunk(int numBottles, int numExchange) {
    int count = numBottles;

    while (numBottles >= numExchange) {
      numBottles -= numExchange - 1;
      ++numExchange;
      ++count;
    }

    return count;
  }
};