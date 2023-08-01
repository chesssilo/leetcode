class Solution:
    def leafSimilar(self, root1: TreeNode, root2: TreeNode) -> bool:
        def getLeaves(node):
            if node is None:
                return
            if node.left is None and node.right is None:
                yield node.val
            yield from getLeaves(node.left)
            yield from getLeaves(node.right)

        return all(a == b for a, b  in zip_longest(getLeaves(root1), getLeaves(root2), fillvalue=None))    