# Time complexity: O(n+mlogm)
# Space complexity: O(1)
class Solution:
  def minimumBoxes(self, apple: List[int], capacity: List[int]) -> int:
    sumApple = sum(apple)
    i = 0
    capacity.sort(reverse=True)

    while i < len(capacity) and sumApple > 0:
      sumApple -= capacity[i]
      i += 1

    return i