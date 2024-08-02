# Time complexity: O(n)
# Space complexity: O(h)
class Solution:
  def btreeGameWinningMove(
    self, root: Optional[TreeNode], n: int, x: int
  ) -> bool:
    leftCount = 0
    rightCount = 0

    def count(root: Optional[TreeNode], x: int) -> int:
      nonlocal leftCount, rightCount

      if not root:
        return 0

      l = count(root.left, x)
      r = count(root.right, x)

      if root.val == x:
        leftCount = l
        rightCount = r

      return 1 + l + r

    count(root, x)

    return max(leftCount, rightCount, n - leftCount - rightCount - 1) > n // 2