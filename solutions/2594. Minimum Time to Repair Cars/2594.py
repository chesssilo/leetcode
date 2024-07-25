# Time complexity: O(log⁡(min⁡(ranks)*cars^2))
# Space complexity: O(1)
class Solution:
  def repairCars(self, ranks: List[int], cars: int) -> int:
    def numCarsFixed(minutes: int) -> int:
      return sum(math.isqrt(minutes // rank) for rank in ranks)
    
    return bisect.bisect_left (
      range(0, min(ranks) * cars**2), cars,
      key=lambda m: numCarsFixed(m))