# Time complexity: O((|queries| + |blocks|) * log(50001))
# Space complexity: O(50001 + |queries| + |blocks|)
class Solution:
  def __init__(self):
    self.segmentTree = []
    self.ans = []

  def getResults(self, queries: List[List[int]]) -> List[bool]:
    self.segmentTree = [0] * (min(50000, 3 * len(queries)) + 1)
    blocks = [0] + sorted(x for t, x, *_ in queries if t == 1)
    self._updateBlocks(blocks)

    for queryType, x, *size in reversed(queries):
      pos = bisect_left(blocks, x)
      if queryType == 1:
        if pos + 1 < len(blocks):
          self._updateSegmentTree(blocks[pos + 1], 
                                  blocks[pos + 1] - blocks[pos - 1])
        del blocks[pos]
      else:
        canPlace = x - blocks[pos - 1] >= size[0] or \
                    self._querySegmentTree(x) >= size[0]
        self.ans.append(canPlace)

    return list(reversed(self.ans))

  def _updateSegmentTree(self, pos: int, value: int) -> None:
    while pos < len(self.segmentTree):
      self.segmentTree[pos] = max(self.segmentTree[pos], value)
      pos |= (pos + 1)

  def _querySegmentTree(self, pos: int) -> int:
    maxValue = 0
    while pos >= 0:
      maxValue = max(maxValue, self.segmentTree[pos])
      pos = (pos & (pos + 1)) - 1

    return maxValue

  def _updateBlocks(self, blocks: List[int]) -> None:
    for i, blockEnd in enumerate(blocks[1:], start=1):
      self._updateSegmentTree(blockEnd, blockEnd - blocks[i - 1])