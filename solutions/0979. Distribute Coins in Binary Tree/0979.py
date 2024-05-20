# Time complexity: O(n)
# Space complexity: O(n)
class Solution:
  def distributeCoins(self, root: Optional[TreeNode]) -> int:
    def dfs(node: Optional[TreeNode]) -> int:
      nonlocal ans
      if not node:
        return 0

      l = dfs(node.left)
      r = dfs(node.right)
      ans += abs(l) + abs(r)

      return node.val - 1 + l + r

    ans = 0
    dfs(root)

    return ans