# Time complexity: O(n*d^2)
# Space complexity: O(h)
class Solution:
  def countPairs(self, root: TreeNode, distance: int) -> int:
    def dfs(root: TreeNode) -> List[int]:
      nonlocal ans
      d = [0] * (distance + 1)

      if not root:
        return d
      if not root.left and not root.right:
        d[0] = 1
        return d

      dl = dfs(root.left)
      dr = dfs(root.right)

      for i in range(distance):
        for j in range(distance):
          if i + j + 2 <= distance:
            ans += dl[i] * dr[j]

      for i in range(distance):
        d[i + 1] = dl[i] + dr[i]

      return d

    ans = 0
    dfs(root)

    return ans