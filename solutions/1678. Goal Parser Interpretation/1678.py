# Time complexity: O(n)
# Space complexity: O(n)
class Solution:
  def interpret(self, command: str) -> str:
    return command.replace('()', 'o').replace('(al)', 'al')