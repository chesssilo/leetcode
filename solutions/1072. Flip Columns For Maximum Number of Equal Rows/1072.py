# Time complexity: O(mn)
# Space complexity: O(mn)
class Solution:
  def maxEqualRowsAfterFlips(self, matrix: List[List[int]]) -> int:
    patternFrequency = {}

    for row in matrix:
      rowPattern = "".join(
        "T" if num == row[0] else "F" for num in row
      )

      patternFrequency[rowPattern] = (
        patternFrequency.get(rowPattern, 0) + 1
      )

    return max(patternFrequency.values(), default=0)