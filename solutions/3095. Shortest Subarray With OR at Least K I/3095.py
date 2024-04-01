# Time complexity: O(n^2)
# Space complexity: O(1)
class Solution:
  def minimumSubarrayLength(self, nums: List[int], k: int) -> int:
    ans = float('inf')

    for i in range(len(nums)):
      curr = nums[i]
      if curr >= k:
        return 1

      for j in range(i+1, len(nums)):
        curr |= nums[j]
        if curr >= k:
          ans = min(ans, j - i + 1)
          break

    return -1 if ans == float('inf') else ans