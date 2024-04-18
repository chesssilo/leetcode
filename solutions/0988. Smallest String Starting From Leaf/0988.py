# Time complexity: O(nh)
# Space complexity: O(n)
class Solution:
  def smallestFromLeaf(self, root: Optional[TreeNode]) -> str:
    self.ans = ""
    self.dfs(root, "")
    return self.ans

  def dfs(self, root: Optional[TreeNode], path: str) -> None:
    if root is None:
      return

    path = chr(root.val + ord('a')) + path

    if root.left is None and root.right is None:
      if not self.ans or self.ans > path:
        self.ans = path
        
    self.dfs(root.left, path)
    self.dfs(root.right, path)