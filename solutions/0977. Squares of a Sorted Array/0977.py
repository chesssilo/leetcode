# Time complexity: O(n)
# Space complexity: O(n)
class Solution:
  def sortedSquares(self, nums: List[int]) -> List[int]:
    n = len(nums)
    ans = [0] * n
    l = 0
    r = n - 1

    while n:
      n -= 1
      if abs(nums[l]) > abs(nums[r]):
        ans[n] = nums[l] * nums[l]
        l += 1
      else:
        ans[n] = nums[r] * nums[r]
        r -= 1

    return ans