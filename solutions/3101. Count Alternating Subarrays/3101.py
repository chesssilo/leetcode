# Time complexity: O(n)
# Space complexity: O(1)
class Solution:
  def countAlternatingSubarrays(self, nums: List[int]) -> int:
    ans = 1
    size = 1

    for i in range(1, len(nums)):
      size = 1 if nums[i - 1] == nums[i] else size + 1
      ans += size

    return ans  