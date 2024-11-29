# Time complexity: O(mn)
# Space complexity: O(mn)
class Solution:
    _dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)]

    def minimumObstacles(self, grid: List[List[int]]) -> int:
      def _is_valid(row: int, col: int) -> bool:
        return 0 <= row < len(grid) and 0 <= col < len(grid[0])

      m, n = len(grid), len(grid[0])
      dist = [[float("inf")] * n for _ in range(m)]
      dist[0][0] = 0
      dequeCells = deque([(0, 0, 0)])

      while dequeCells:
        obstacles, row, col = dequeCells.popleft()

        for dr, dc in self._dirs:
          newRow, newCol = row + dr, col + dc

          if _is_valid(newRow, newCol) and \
             dist[newRow][newCol] == float("inf"):
            if grid[newRow][newCol] == 1:
              dist[newRow][newCol] = obstacles + 1
              dequeCells.append((obstacles + 1, newRow, newCol))
            else:
              dist[newRow][newCol] = obstacles
              dequeCells.appendleft((obstacles, newRow, newCol))

      return dist[m - 1][n - 1]