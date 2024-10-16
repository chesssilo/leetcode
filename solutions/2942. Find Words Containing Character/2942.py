# Time complexity: O(nm)
# Space complexity: O(k)
class Solution:
  def findWordsContaining(self, words: List[str], x: str) -> List[int]:
    return [i for i, word in enumerate(words) if x in word]