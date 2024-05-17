# Time complexity: O(nlogk)
# Space complexity: O(n)
class Solution:
  def findProductsOfElements(self, queries: List[List[int]]) -> List[int]:
    def sumBitsTill(x: int) -> int:
      sumBits = 0
      powerOfTwo = 1
      while powerOfTwo <= x:
        sumBits += (x // (2 * powerOfTwo)) * powerOfTwo
        sumBits += max(0, x % (2 * powerOfTwo) + 1 - powerOfTwo)
        powerOfTwo *= 2

      return sumBits

    def sumPowersTill(x: int) -> int:
      sumPowers = 0
      powerOfTwo = 1
      for power in range(x.bit_length()):
        sumPowers += (x // (2 * powerOfTwo)) * powerOfTwo * power
        sumPowers += max(0, x % (2 * powerOfTwo) + 1 - powerOfTwo) * power
        powerOfTwo *= 2

      return sumPowers

    def sumPowersFirstKBigNums(k: int) -> int:
      num = bisect.bisect_left(range(k), k, key=sumBitsTill)
      sumPowers = sumPowersTill(num - 1)
      remainingCount = k - sumBitsTill(num - 1)
      for power in range(num.bit_length()):
        if num >> power & 1:
          sumPowers += power
          remainingCount -= 1
          if remainingCount == 0:
            break

      return sumPowers

    return [pow(2,
                sumPowersFirstKBigNums(b + 1) -
                sumPowersFirstKBigNums(a), mod)
            for a, b, mod in queries]