# Time complexity: O(n)
# Space complexity: O(n)
class Solution:
  def findMode(self, root: Optional[TreeNode]) -> List[int]:
    count = {}
        
    def inorder(node):
      if node:
        inorder(node.left)
        count[node.val] = count.get(node.val, 0) + 1
        inorder(node.right)

    inorder(root)
    max_count = max(count.values())
    
    return [val for val, freq in count.items() if freq == max_count]