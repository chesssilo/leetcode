# Time complexity: O(n)
# Space complexity: O(n)
class Solution:
    def in_order_traversal(self, node: TreeNode) -> None:
        if node is None:
            return
        self.in_order_traversal(node.left)
        if self.prev is not None:
            self.min_diff = min(self.min_diff, abs(node.val - self.prev.val))
        self.prev = node
        self.in_order_traversal(node.right)

    def minDiffInBST(self, root: Optional[TreeNode]) -> int:
        self.prev = None
        self.min_diff = float('inf')
        self.in_order_traversal(root)
        return self.min_diff