# Time complexity: O(n)
# Space complexity: O(h)
class Solution:
  def bstToGst(self, root: TreeNode) -> TreeNode:
    pref = 0

    def reversedInorder(node: TreeNode):
      nonlocal pref
      if not node:
        return

      reversedInorder(node.right)

      node.val += pref
      pref = node.val

      reversedInorder(node.left)

    reversedInorder(root)
    return root