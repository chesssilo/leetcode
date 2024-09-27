# Time complexity: O(nlogn)
# Space complexity: O(n)
from sortedcontainers import SortedDict

class MyCalendar:
  def __init__(self) -> None:
    self.timeline = SortedDict()

  def book(self, start: int, end: int) -> bool:
    lo = self.timeline.bisect_left(end)

    if lo == 0 or self.timeline.peekitem(lo - 1)[1] <= start:
      self.timeline[start] = end
      return True

    return False