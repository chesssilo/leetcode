# Time complexity: O(n)
# Space complexity: O(n)
class Solution:
  def duplicateNumbersXOR(self, nums: List[int]) -> int:
    count = Counter(nums)
    ans = 0

    for num, freq in count.items():
      if freq == 2:
        ans ^= num

    return ans    