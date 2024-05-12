# Time complexity: O(log⁡n)
# Space complexity: O(1)
class Solution :
  def peakIndexInMountainArray(self, arr: List[int]) -> int:
    l = 0
    r = len(arr)

    while l < r:
      m = l + (r - l) // 2
      if arr[m] >= arr[m + 1]: 
        r = m
      else:
        l = m + 1

    return l