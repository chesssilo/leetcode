# Time complexity: O(n)
# Space complexity: O(n)
class Solution:
  def subarraysWithKDistinct(self, nums: List[int], k: int) -> int:
    def subarraysWithAtMostKDistinct(k: int) -> int:
      ans = 0
      count = collections.Counter()

      l = 0
      for r, num in enumerate(nums):
        count[num] += 1
        if count[num] == 1:
          k -= 1
        while k < 0:
          count[nums[l]] -= 1
          if count[nums[l]] == 0:
            k += 1
          l += 1
        ans += r - l + 1

      return ans

    return subarraysWithAtMostKDistinct(k) - subarraysWithAtMostKDistinct(k - 1)