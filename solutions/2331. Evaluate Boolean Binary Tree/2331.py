# Time complexity: O(n)
# Space complexity: O(h)
class Solution:
  def evaluateTree(self, root: Optional[TreeNode]) -> bool:
    if root.val < 2:
      return root.val
    if root.val == 2:
      return self.evaluateTree(root.left) or self.evaluateTree(root.right)

    return self.evaluateTree(root.left) and self.evaluateTree(root.right)