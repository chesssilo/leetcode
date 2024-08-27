# Time complexity: O(n)
# Space complexity: O(n)
class Solution:
  def postorder(self, root: 'Node') -> List[int]:
    if root is None:
      return []

    ans = []
    stack = [root]

    while stack:
      curr = stack.pop()
      ans.append(curr.val)
      stack.extend(curr.children)

    ans.reverse()
    return ans