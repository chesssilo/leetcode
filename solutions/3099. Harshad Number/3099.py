# Time complexity: O(logn)
# Space complexity: O(1)
class Solution:
  def sumOfTheDigitsOfHarshadNumber(self, x: int) -> int:
    sumX = 0
    n = x

    while n > 0:
      sumX += n % 10
      n //= 10

    return sumX if x % sumX == 0 else -1