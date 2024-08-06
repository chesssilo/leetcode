# Time Complexity: O(n)
# Space Complexity: O(n)
class Solution:
  def increasingBST(self, root: TreeNode, tail: TreeNode = None) -> TreeNode:
    if not root:
      return tail

    ans = self.increasingBST(root.left, root)
    root.left = None
    root.right = self.increasingBST(root.right, tail)

    return ans