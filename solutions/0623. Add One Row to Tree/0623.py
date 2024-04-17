# Time complexity: O(n)
# Space complexity: O(h)
class Solution:
  def addOneRow(self, root: Optional[TreeNode], 
                val: int, depth: int) -> Optional[TreeNode]:
    if depth == 1:
      return TreeNode(val, root, None)
    
    if root is None:
      return TreeNode(val)
    
    self.addRow(root, val, depth, 1)

    return root
  
  def addRow(self, node: TreeNode, val: int, 
             depth: int, currDepth: int) -> None:
    if node is None:
      return
    
    if currDepth == depth - 1:
      node.left = TreeNode(val, node.left, None)
      node.right = TreeNode(val, None, node.right)
      return
    
    self.addRow(node.left, val, depth, currDepth + 1)
    self.addRow(node.right, val, depth, currDepth + 1)