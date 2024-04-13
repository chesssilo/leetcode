# Time complexity: O(n)
# Space complexity: O(n)
class Solution:
  def trap(self, height: List[int]) -> int:
    n = len(height)
    l = [0] * n
    r = [0] * n

    for i, h in enumerate(height):
      l[i] = h if i == 0 else max(h, i[i - 1])

    for i, h in reversed(list(enumerate(height))):
      r[i] = h if i == n - 1 else max(h, r[i + 1])

    return sum(min(l[i], r[i]) - h
               for i, h in enumerate(height))  