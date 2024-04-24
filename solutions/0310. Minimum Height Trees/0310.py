# Time complexity: O(V+E)
# Space complexity: O(V+E)
class Solution:
  def findMinHeightTrees(self, n: int, edges: List[List[int]]) -> List[int]:
    if n == 1 or not edges:
      return [0]
    
    graph = [[] for _ in range(n)]
    degree = [0] * n

    for edge in edges:
      u, v = edge[0], edge[1]
      graph[u].append(v)
      graph[v].append(u)
      degree[u] += 1
      degree[v] += 1

    leaves = [i for i, d in enumerate(degree) if d <= 1]

    while n > 2:
      next_leaves = []

      for u in leaves:
        for v in graph[u]:
          degree[v] -= 1
          if degree[v] == 1:
            next_leaves.append(v)
        n -= 1
      leaves = next_leaves

    return leaves          