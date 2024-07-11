# Time complexity: O(n)
# Space complexity: O(1)
class Solution:
  def minOperations(self, logs: List[str]) -> int:
    return reduce(
      lambda acc, log: max(0, acc - 1) if log == "../" else
                       acc + 1 if log != "./" else acc,
      logs,
      0
    )