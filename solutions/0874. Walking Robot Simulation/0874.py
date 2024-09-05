# Time Complexity: O(m+n)
# Space Complexity: O(n)
class Solution:
  def robotSim(self, commands: List[int], obstacles: List[List[int]]) -> int:
    dirs = [(0, 1), (1, 0), (0, -1), (-1, 0)]
    ans = 0
    x = 0
    y = 0
    d = 0
    obstacleSet = set(map(tuple, obstacles))

    for command in commands:
      if command == -2:
        d = (d - 1) % 4
      elif command == -1:
        d = (d + 1) % 4
      else:
        for _ in range(command):
          nextX = x + dirs[d][0]
          nextY = y + dirs[d][1]
          if (nextX, nextY) not in obstacleSet:
            x = nextX
            y = nextY
            ans = max(ans, x * x + y * y)

    return ans