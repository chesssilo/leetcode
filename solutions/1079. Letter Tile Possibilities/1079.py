# Time complexity: O(n^26)
# Space complexity: O(n)
class Solution:
  def numTilePossibilities(self, tiles: str) -> int:
    count = collections.Counter(tiles)

    def dfs(count: Dict[int, int]) -> int:
      possibleSequences = 0

      for k, v in count.items():
        if v == 0:
          continue
        count[k] -= 1
        possibleSequences += 1 + dfs(count)
        count[k] += 1

      return possibleSequences

    return dfs(count)