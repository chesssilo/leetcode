# Time complexity: O(mn)
# Space complexity: O(1)
class Solution:
  def modifiedMatrix(self, matrix: List[List[int]]) -> List[List[int]]:
    rows = len(matrix)
    cols = len(matrix[0])

    for i in range(cols):
      maxVal = 0
      for j in range(rows):
        maxVal = max(maxVal, matrix[j][i])

      for j in range(rows):
        if matrix[j][i] == -1:
          matrix[j][i] = maxVal

    return matrix