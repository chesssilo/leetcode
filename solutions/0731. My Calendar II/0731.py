# Time complexity: O(n)
# Space complexity: O(n)
class MyCalendarTwo:
  def __init__(self) -> None:
    self.timeline = []
    self.overlapTimeline = []

  def book(self, start: int, end: int) -> bool:
    for start1, end1 in self.overlapTimeline:
      if self._doesOverlap(start1, end1, start, end):
        return False

    for start1, end1 in self.timeline:
      if self._doesOverlap(start1, end1, start, end):
        self.overlapTimeline.append(
          self._getOverlapped(start1, end1, start, end)
        )

    self.timeline.append((start, end))
    return True

  def _doesOverlap(
    self, start1: int, end1: int, start2: int, end2: int
  ) -> bool:
    return max(start1, start2) < min(end1, end2)

  def _getOverlapped(
    self, start1: int, end1: int, start2: int, end2: int
  ) -> tuple:
    return max(start1, start2), min(end1, end2)