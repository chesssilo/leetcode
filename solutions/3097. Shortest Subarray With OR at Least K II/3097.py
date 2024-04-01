# Time complexity: O(n)
# Space complexity: O(1)
class Solution:
  def update(self, bits: List[int], x: int, change: int) -> None:
    for i in range(32):
      if (x >> i) & 1 != 0:
        bits[i] += change

  def bitsToNum(self, bits: List[int]) -> int:
    res = 0

    for i in range(32):
      if bits[i] != 0:
        res |= 1 << i

    return res        

  def minimumSubarrayLength(self, nums: List[int], k: int) -> int:
    ans = len(nums) + 1
    bits = [0] * 32

    l = 0
    for r in range(len(nums)):
      self.update(bits, nums[r], 1)

      while l <= r and self.bitsToNum(bits) >= k:
        ans = min(ans, r - l + 1)
        self.update(bits, nums[l], -1)
        l += 1

    return ans if ans != len(nums) + 1 else -1