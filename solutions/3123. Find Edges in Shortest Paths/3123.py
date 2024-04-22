# Time complexity: O((n+m)logn)
# Space complexity: O(n+m)
class Solution:
  def findAnswer(self, n: int, edges: List[List[int]]) -> List[bool]:
    INF = 1_000_000_007
    graph = [[] for _ in range(n)]
    dist = [INF] * n
    edgeIndex = [[] for _ in range(n)]
    ans = [False] * len(edges)

    for i in range(len(edges)):
      u, v, w = edges[i]
      graph[u].append((v, w))
      graph[v].append((u, w))
      edgeIndex[u].append(i)
      edgeIndex[v].append(i)

    pq = [(0, 0)]
    dist[0] = 0

    while pq:
      u = heapq.heappop(pq)[1]

      for i in range(len(graph[u])):
        v, w = graph[u][i]

        if dist[u] + w < dist[v]:
          dist[v] = dist[u] + w
          heapq.heappush(pq, (dist[v], v))

    q = [n - 1]

    while q:
      u = q.pop(0)

      for i in range(len(graph[u])):
        v, w = graph[u][i]
        idx = edgeIndex[u][i]

        if dist[u] == dist[v] + w:
          ans[idx] = True
          if v != 0:
            q.append(v)

    return ans