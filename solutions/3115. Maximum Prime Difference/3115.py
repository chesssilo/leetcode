# Time complexity: O(n)
# Space complexity: O(1)
class Solution:
  def maximumPrimeDifference(self, nums: List[int]) -> int:
    l = 0
    r = len(nums) - 1
    ans = 0

    while l < r:
      if self.isPrime(nums[l]) and self.isPrime(nums[r]):
        ans = abs(r - l)
        break

      if not self.isPrime(nums[l]):
        l += 1
      if not self.isPrime(nums[r]):
        r -= 1

    return ans

  def isPrime(self, num: int) -> bool:
    if num <= 1:
      return False

    for i in range(2, math.isqrt(num) + 1):
      if num % i == 0:
        return False

    return True