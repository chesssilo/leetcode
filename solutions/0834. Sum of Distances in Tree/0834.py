# Time complexity: O(n)
# Space complexity: O(n)
class Solution:
  def sumOfDistancesInTree(self, n: int, edges: List[List[int]]) -> List[int]:
    ans = [0] * n
    count = [1] * n
    tree = collections.defaultdict(set)

    for u, v in edges:
      tree[u].add(v)
      tree[v].add(u)

    def postorder(node, parent=None) -> None:
      for child in tree[node]:
        if child == parent:
          continue
        postorder(child, node)
        count[node] += count[child]
        ans[node] += ans[child] + count[child]

    def preorder(node, parent=None) -> None:
      for child in tree[node]:
        if child == parent:
          continue
        ans[child] = ans[node] - count[child] + (n - count[child])
        preorder(child, node)

    postorder(0)
    preorder(0)

    return ans