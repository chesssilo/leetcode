# Time complexity: O(sort)
# Space complexity: O(n)
class Solution:
  def sortJumbled(self, mapping: List[int], nums: List[int]) -> List[int]:
    def getMapped(num: int) -> int:
      if num == 0:
        return mapping[0]

      mapped = 0
      multiplier = 1

      while num > 0:
        digit = num % 10
        mapped += mapping[digit] * multiplier
        num //= 10
        multiplier *= 10

      return mapped

    A = [(getMapped(num), num) for num in nums]
    A.sort(key=lambda x: x[0])

    return [num for _, num in A]