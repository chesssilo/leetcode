# Time complexity: O(sort)
# Space complexity: O(n)
class Solution:
  def frequencySort(self, nums: List[int]) -> List[int]:
    freq = Counter(nums)
    return nums.sort(key=lambda x: (freq[x], -x))