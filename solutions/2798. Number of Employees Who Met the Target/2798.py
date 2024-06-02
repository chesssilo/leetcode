# Time complexity: O(n)
# Space complexity: O(1)
class Solution:
  def numberOfEmployeesWhoMetTarget(self, hours: List[int], 
                                    target: int) -> int:
    ans = 0

    for hour in hours:
      if hour >= target:
        ans += 1

    return ans