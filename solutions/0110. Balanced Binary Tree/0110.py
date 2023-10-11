# Time complexity: O(n)
# Space complexity: O(h)
class Solution:
    def isBalanced(self, root: Optional[TreeNode]) -> bool:
        return self.getHeight(root) != -1

    def getHeight(self, node: Optional[TreeNode]) -> int:
        if node is None:
            return 0
        leftH = self.getHeight(node.left)
        if leftH == -1:
            return -1
        rightH = self.getHeight(node.right)
        if rightH == -1:
            return -1
        if abs(leftH - rightH) > 1:
            return -1
        else:
            return max(leftH, rightH) + 1