# Time complexity: O(nm)
# Space complexity: O(1)
class Solution:
  def mostWordsFound(self, sentences: List[str]) -> int:
    return max(s.count(' ') for s in sentences) + 1