# Time complexity: O(n)
# Space complexity: O(n)
class Solution:
  def countTriplets(self, arr: List[int]) -> int:
    ans = 0
    pref  = 0
    countMap = defaultdict(int, {0: 1})
    totalMap = defaultdict(int)

    for i, val in enumerate(arr):
      pref ^= val
      ans += countMap[pref] * i - totalMap[pref]
      countMap[pref] += 1
      totalMap[pref] += i + 1

    return ans