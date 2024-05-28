# Time complexity: O(n+q)
# Space complexity: O(n+q)
class Solution:
  def occurrencesOfElement(self, nums: List[int], queries: List[int], x: int) -> List[int]:
    indices = [i for i, num in enumerate(nums) if num == x]
    return [indices[query - 1] if query <= len(indices) else -1
            for query in queries]