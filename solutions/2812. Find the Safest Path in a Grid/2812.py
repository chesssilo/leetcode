# Time complexity: O(n^2)
# Space complexity: O(n^2)
class Solution:
  def maximumSafenessFactor(self, grid: List[List[int]]) -> int:
    n = len(grid)
    bounds_check = lambda r, c: r >= 0 and c >= 0 and r < n and c < n

    q = deque()
    for i in range(n):
      for j in range(n):
        if grid[i][j] != 0:
          q.append((i, j, 1))
        grid[i][j] -= 1

    while q:
      i, j, safety = q.popleft()
      expand = [(i + 1, j), (i - 1, j), (i, j + 1), (i, j - 1)]
      for r, c in expand:
        if bounds_check(r, c) and grid[r][c] == -1:
          grid[r][c] = safety
          q.append((r, c, safety + 1))

    min_safety = grid[0][0]
    q.append((0, 0, grid[0][0]))

    while q:
      i, j, safety = q.popleft()
      min_safety = min(min_safety, safety)
      if i == n - 1 and j == n - 1:
        break

      expand = [(i + 1, j), (i - 1, j), (i, j + 1), (i, j - 1)]
      for r, c in expand:
        if bounds_check(r, c) and grid[r][c] != -1:
          safety = grid[r][c]
          grid[r][c] = -1
          if safety < min_safety:
            q.append((r, c, safety))
          else:
            q.appendleft((r, c, safety))

    return min_safety