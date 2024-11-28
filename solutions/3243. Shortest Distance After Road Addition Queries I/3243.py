# Time complexity: O(q(n+q))
# Space complexity: O(n+q)
class Solution:
  def shortestDistanceAfterQueries(
    self, n: int, queries: List[List[int]],
  ) -> List[int]:
    ans = []
    dist = list(range(n))
    graph = [[] for _ in range(n)]

    for i in range(n - 1):
      graph[i].append(i + 1)

    for u, v in queries:
      graph[u].append(v)
      if dist[u] + 1 < dist[v]:
        dist[v] = dist[u] + 1
        self._bfs(graph, v, dist)
      ans.append(dist[n - 1])

    return ans

  def _bfs(self, graph: List[List[int]], start: int, dist: List[int]) -> None:
    q = collections.deque([start])
    while q:
      u = q.popleft()
      for v in graph[u]:
        if dist[u] + 1 < dist[v]:
          dist[v] = dist[u] + 1
          q.append(v)