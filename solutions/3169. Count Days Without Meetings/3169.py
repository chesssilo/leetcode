# Time complexity: O(sort)
# Space complexity: O(sort)
class Solution:
  def countDays(self, days: int, meetings: List[List[int]]) -> int:
    meetings.sort()
    workUntil = 0
    ans = 0

    for meeting in meetings:
      if meeting[0] > workUntil:
        ans += meeting[0] - workUntil - 1
      workUntil = max(workUntil, meeting[1])

    return ans + days - workUntil