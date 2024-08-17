# Time complexity: O(n)
# Space complexity: O(1)
class Solution:
  def maxDistance(self, arrays: List[List[int]]) -> int:
    ans = 0
    mn = 10000
    mx = -10000

    for arr in arrays:
      ans = max(ans, arr[-1] - mn, mx - arr[0])
      mn = min(mn, arr[0])
      mx = max(mx, arr[-1])

    return ans