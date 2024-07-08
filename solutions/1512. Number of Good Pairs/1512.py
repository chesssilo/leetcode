# Time complexity: O(n)
# Space complexity: O(1)
class Solution:
  def numIdenticalPairs(self, nums: List[int]) -> int:
    ans = 0
    count = [0] * 101

    for num in nums:
      ans += count[num]
      count[num] += 1

    return ans