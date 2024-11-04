# Time complexity: O(n)
# Space complexity: O(n)
class Solution:
  def rotateString(self, s: str, goal: str) -> bool:
    return len(s) == len(goal) and goal in s + s