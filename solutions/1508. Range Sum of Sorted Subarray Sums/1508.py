# Time complexity: O(nlog(S))
# Space complexity: O(1)
class Solution:
  def rangeSum(self, nums: List[int], n: int, left: int, right: int) -> int:
    kMod = 1_000_000_007

    def subarraysAndSumNoGreaterThan(m: int) -> Tuple[int, int]:
      count = 0
      total = 0
      currentSum = 0
      window = 0

      i = 0
      for j in range(n):
        currentSum += nums[j] * (j - i + 1)
        window += nums[j]

        while window > m:
          currentSum -= window
          window -= nums[i]
          i += 1

        count += j - i + 1
        total += currentSum

      return (count, total)

    L = min(nums)
    R = sum(nums)

    def firstKSubarraysSum(k: int) -> int:
      l = L
      r = R

      while l < r:
        m = l + (r - l) // 2
        if subarraysAndSumNoGreaterThan(m)[0] < k:
          l = m + 1
        else:
          r = m

      count, total = subarraysAndSumNoGreaterThan(l)
      return total - l * (count - k)

    return (firstKSubarraysSum(right) - firstKSubarraysSum(left - 1)) % kMod