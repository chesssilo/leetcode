# Time complexity: O(n)
# Space complexity: O(1)
class Solution:
  def countSeniors(self, details: List[int]) -> int:
    return sum(int(detail[11:13]) > 60 for detail in details)