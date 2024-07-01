# Time complexity: O(sort)
# Space complexity: O(n)
class UnionFind:
  def __init__(self, n: int):
    self.count = n
    self.id = list(range(n))
    self.rank = [0] * n

  def unionByRank(self, u: int, v: int) -> bool:
    i = self._find(u)
    j = self._find(v)
    if i == j:
      return False
    if self.rank[i] < self.rank[j]:
      self.id[i] = j
    elif self.rank[i] > self.rank[j]:
      self.id[j] = i
    else:
      self.id[i] = j
      self.rank[j] += 1
    self.count -= 1

    return True

  def _find(self, u: int) -> int:
    if self.id[u] != u:
      self.id[u] = self._find(self.id[u])
    return self.id[u]

class Solution:
  def maxNumEdgesToRemove(self, n: int, edges: List[List[int]]) -> int:
    alice = UnionFind(n)
    bob = UnionFind(n)
    requiredEdges = 0

    for type, u, v in sorted(edges, reverse=True):
      u -= 1
      v -= 1
      if type == 3:
        if alice.unionByRank(u, v) | bob.unionByRank(u, v):
          requiredEdges += 1
      elif type == 2:
        if bob.unionByRank(u, v):
          requiredEdges += 1
      else:
        if alice.unionByRank(u, v):
          requiredEdges += 1

    return len(edges) - requiredEdges \
        if alice.count == 1 and bob.count == 1 \
        else -1