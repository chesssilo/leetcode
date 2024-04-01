# Time complexity: O(n)
# Space complexity: O(1)
class Solution:
  def maxBottlesDrunk(self, numBottles: int, numExchange: int) -> int:
    count = numBottles

    while numBottles >= numExchange:
      numBottles -= numExchange - 1
      numExchange += 1
      count += 1

    return count