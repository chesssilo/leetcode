# Time complexity: O(n)
# Space complexity: O(h)
class Solution:
    def maxAncestorDiff(self, root: Optional[TreeNode]) -> int:
        def dfs(root: Optional[TreeNode], mini: int, maxi: int) -> int:
            if not root:
                return 0
            mini = min(mini, root.val)
            maxi = max(maxi, root.val)
            left = dfs(root.left, mini, maxi)
            right = dfs(root.right, mini, maxi)

            return max(maxi - mini, left, right)

        return dfs(root, root.val, root.val)   