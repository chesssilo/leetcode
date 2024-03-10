# Time complexity: O(d)
# Space complexity: O(1)
class Solution:
  def countDigits(self, num: int) -> int:
    ans = 0

    n = num
    while n > 0:
      if num % (n % 10) == 0:
        ans += 1
      n //= 10

    return ans