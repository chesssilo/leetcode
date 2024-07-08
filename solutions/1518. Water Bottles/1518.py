# Time complexity: O(1)
# Space complexity: O(1)
class Solution:
  def numWaterBottles(self, numBottles: int, numExchange: int) -> int:
    return numBottles + (numBottles - 1) // (numExchange - 1)