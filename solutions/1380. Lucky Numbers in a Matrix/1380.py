# Time complexity: O(nm)
# Space complexity: O(1)
class Solution:
  def luckyNumbers(self, matrix: List[List[int]]) -> List[int]:
    for row in matrix:
      minIndex = row.index(min(row))
      if row[minIndex] == max(list(zip(*matrix))[minIndex]):
        return [row[minIndex]]

    return []