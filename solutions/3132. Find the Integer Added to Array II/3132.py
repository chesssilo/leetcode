# Time complexity: O(sort)
# Space complexity: O(sort)
class Solution:
  def minimumAddedInteger(self, nums1: List[int], nums2: List[int]) -> int:
    nums1.sort()
    nums2.sort()
    ans = float('inf')

    for i in range(len(nums1)):
      x = nums2[0] - nums1[i]
      if self.check(nums1, nums2, x):
        ans = min(ans, x)

    return ans

  def check(self, nums1: List[int], nums2: List[int], x: int) -> bool:
    count = 0
    j = 0

    for i in range(len(nums1)):
      if j < len(nums2):
        if nums1[i] + x != nums2[j]:
          count += 1
        else:
          j += 1
      else:
        break

    return count <= 2