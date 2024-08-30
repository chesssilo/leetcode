# Time complexity: O(n)
# Space complexity: O(n)
class UnionFind:
  def __init__(self, n: int):
    self.parent = [-1] * n
    self.component_count = 0
    self.unique_nodes = set()

  def find(self, node: int) -> int:
    if node not in self.unique_nodes:
      self.component_count += 1
      self.unique_nodes.add(node)

    if self.parent[node] == -1:
      return node

    self.parent[node] = self.find(self.parent[node])
    return self.parent[node]

  def unionNodes(self, node1: int, node2: int):
    root1 = self.find(node1)
    root2 = self.find(node2)

    if root1 != root2:
      self.parent[root1] = root2
      self.component_count -= 1

class Solution:
  def removeStones(self, stones: List[List[int]]) -> int:
    uf = UnionFind(20002)

    for stone in stones:
      uf.unionNodes(stone[0], stone[1] + 10001)

    return len(stones) - uf.component_count