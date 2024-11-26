# Time complexity: O((mn)!)
# Space complexity: O((mn)!)
class Solution:
  def slidingPuzzle(self, board: List[List[int]]) -> int:
    dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)]
    m, n = 2, 3
    goal = "123450"
    start = ''.join(str(board[i][j]) for i in range(m) for j in range(n))

    if start == goal:
      return 0

    q = deque([start])
    seen = {start}

    step = 0
    while q:
      step += 1
      for _ in range(len(q)):
        s = q.popleft()
        zeroIndex = s.index('0')
        i, j = divmod(zeroIndex, n)

        for dx, dy in dirs:
          x, y = i + dx, j + dy
          if 0 <= x < m and 0 <= y < n:
            swappedIndex = x * n + y
            newS = list(s)
            newS[zeroIndex], newS[swappedIndex] = \
            newS[swappedIndex], newS[zeroIndex]
            newS = ''.join(newS)
            if newS == goal:
              return step
            if newS not in seen:
              seen.add(newS)
              q.append(newS)

    return -1