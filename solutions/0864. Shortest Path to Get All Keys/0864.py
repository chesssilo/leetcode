# Time Complexity: O(mn2^k)
# Space Complexity: O(mn2^k)
from collections import deque
from typing import List

class Solution:
  def shortestPathAllKeys(self, grid: List[str]) -> int:
    dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)]
    m, n = len(grid), len(grid[0])
    keysCount = self._getKeysCount(grid)
    kKeys = (1 << keysCount) - 1
    start = self._getStart(grid)
    q = deque([(start[0], start[1], 0)])
    seen = [[[False] * (kKeys + 1) for _ in range(n)] for _ in range(m)]
    seen[start[0]][start[1]][0] = True

    for step in range(1, m * n * (kKeys + 1)):
      for _ in range(len(q)):
        i, j, keys = q.popleft()
        for dx, dy in dirs:
          x, y = i + dx, j + dy
          if x < 0 or x >= m or y < 0 or y >= n:
            continue
          c = grid[x][y]
          if c == '#':
            continue
          if 'a' <= c <= 'f':
            newKeys = keys | (1 << (ord(c) - ord('a')))
          else:
            newKeys = keys
          if newKeys == kKeys:
            return step
          if seen[x][y][newKeys]:
            continue
          if 'A' <= c <= 'F' and not (newKeys >> (ord(c) - ord('A')) & 1):
            continue
          q.append((x, y, newKeys))
          seen[x][y][newKeys] = True

    return -1

  def _getKeysCount(self, grid: List[str]) -> int:
    return sum(c in 'abcdef' for row in grid for c in row)

  def _getStart(self, grid: List[str]) -> List[int]:
    for i, row in enumerate(grid):
      for j, c in enumerate(row):
        if c == '@':
          return [i, j]
    raise ValueError("Start position not found")