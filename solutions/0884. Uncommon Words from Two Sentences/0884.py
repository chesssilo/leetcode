# Time complexity: O(m+n)
# Space complexity: O(m+n)
class Solution:
  def uncommonFromSentences(self, s1: str, s2: str) -> List[str]:
    count = collections.Counter((s1 + ' ' + s2).split())
    return [word for word, freq in count.items() if freq == 1]