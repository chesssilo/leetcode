# Time complexity: O(sort)
# Space complexity: O(n)
class Solution:
  def sortPeople(self, names: List[str], heights: List[int]) -> List[str]:
    return [
      height for _, height in sorted(
        [(height, name) for name, height in zip(names, heights)],
        reverse=True
      )
    ]