# Time complexity: O(V+E)
# Space complexity: O(V+E)
class Solution:
  def secondMinimum(
    self,
    n: int,
    edges: List[List[int]],
    time: int,
    change: int
  ) -> int:
    graph = [[] for _ in range(n + 1)]
    q = collections.deque([(1, 0)])
    minTime = [[math.inf] * 2 for _ in range(n + 1)]
    minTime[1][0] = 0

    for u, v in edges:
      graph[u].append(v)
      graph[v].append(u)

    while q:
      i, prevTime = q.popleft()
      numChangeSignal = prevTime // change
      waitTime = 0 if numChangeSignal % 2 == 0  \
        else change - (prevTime % change)
      newTime = prevTime + waitTime + time
      for j in graph[i]:
        if newTime < minTime[j][0]:
          minTime[j][0] = newTime
          q.append((j, newTime))
        elif minTime[j][0] < newTime < minTime[j][1]:
          if j == n:
            return newTime
          minTime[j][1] = newTime
          q.append((j, newTime))