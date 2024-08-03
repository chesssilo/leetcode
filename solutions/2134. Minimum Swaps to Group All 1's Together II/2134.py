# Time complexity: O(n)
# Space complexity: O(1)
class Solution:
  def minSwaps(self, nums: List[int]) -> int:
    n = len(nums)
    k = nums.count(1)
    ones = 0
    maxOnes = 0

    for i in range(n * 2):
      if i >= k and nums[i % n - k]:
        ones -= 1
      if nums[i % n]:
        ones += 1
      maxOnes = max(maxOnes, ones)

    return k - maxOnes