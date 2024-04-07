# Time complexity: O(n)
# Space complexity: O(n)
class Solution:
  def minRemoveToMakeValid(self, s: str) -> str:
    stack = []
    chars = [c for c in s]

    for i, c in enumerate(chars):
      if c =='(':
        stack.append(i)
      elif c == ')':
        if stack:
          stack.pop()
        else:
          chars[i] = '*'

    while stack:
      chars[stack.pop()] = '*'

    return ''.join(chars).replace('*', '')