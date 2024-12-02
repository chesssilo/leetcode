# Time complexity: O(1)
# Space complexity: O(1)
class Solution:
  def numberOfSteps(self, num: int) -> int:
    if num == 0:
      return 0
    subtractSteps = num.bit_count()
    divideSteps = num.bit_length() - 1
    return subtractSteps + divideSteps