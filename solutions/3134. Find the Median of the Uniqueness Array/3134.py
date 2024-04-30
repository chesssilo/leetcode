# Time complexity: O(nlogn)
# Space complexity: O(n)
class Solution:
  def medianOfUniquenessArray(self, nums: List[int]) -> int:
    n = len(nums)
    totalSubarrays = n * (n + 1) // 2
    left, right = 1, n

    while left < right:
      mid = left + (right - left) // 2
      if self.countAtLeastKdistinct(nums, mid) * 2 >= totalSubarrays:
        right = mid
      else:
        left = mid + 1

    return left

  def countAtLeastKdistinct(self, nums: List[int], k: int) -> int:
    count = 0
    left = 0
    freq = defaultdict(int)

    for right in range(len(nums)):
      freq[nums[right]] += 1

      while len(freq) > k:
        freq[nums[left]] -= 1
        if freq[nums[left]] == 0:
          del freq[nums[left]]
        left += 1

      count += right - left + 1

    return count