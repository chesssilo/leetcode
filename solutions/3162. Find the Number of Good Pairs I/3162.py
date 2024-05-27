# Time complexity: O(n*sqrt(m))
# Space complexity: O(n*sqrt(m))
class Solution:
  def numberOfPairs(self, nums1: List[int], nums2: List[int], k: int) -> int:
    count = defaultdict(int)
    ans = 0

    for num in nums1:
      for i in range(1, int(num ** 0.5) + 1):
        if num % i == 0:
          count[i] += 1
          if i * i != num:
            count[num // i] += 1

    for num in nums2:
      num = num * k
      ans += count.get(num, 0)

    return ans