# Time complexity: O(nlogn)
# Space complexity: O(n)
class Solution:
  def maxPalindromesAfterOperations(self, words: List[str]) -> int:
    count , ans  = Counter([c for word in words for c in word]), 0
    pairs = sum(charCount // 2 for charCount in count.values())
    for length in sorted([len(word) for word in words]):
      pairs -= length // 2
      ans += pairs >= 0

    return ans 