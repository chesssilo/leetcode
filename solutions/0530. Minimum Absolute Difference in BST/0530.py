# Time complexity: O(n)
# Space complexity: O(n)
class Solution:
    def getMinimumDifference(self, root: Optional[TreeNode]) -> int:
        self.min_diff = float('inf')
        self.prev = None
        
        def inOrderTraversal(node):
            if node is None:
                return
            
            inOrderTraversal(node.left)
            
            if self.prev is not None:
                self.min_diff = min(self.min_diff, node.val - self.prev.val)
            
            self.prev = node
            
            inOrderTraversal(node.right)
        
        inOrderTraversal(root)
        return self.min_diff