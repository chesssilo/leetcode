// Time complexity: O(n)
// Space complexity: O(n)
class MyCalendarTwo {
 public:
  MyCalendarTwo() {}

  bool book(int start, int end) {
    for (const auto& time : overlapTimeline)
      if (doesOverlap(time.first, time.second, start, end))
        return false;

    for (const auto& time : timeline)
      if (doesOverlap(time.first, time.second, start, end))
        overlapTimeline.push_back(
          getOverlapped(time.first, time.second, start, end));

    timeline.push_back({start, end});
    return true;
  }

 private:
  vector<pair<int, int>> timeline;
  vector<pair<int, int>> overlapTimeline;

  bool doesOverlap(int start1, int end1, int start2, int end2) {
    return max(start1, start2) < min(end1, end2);
  }

  pair<int, int> getOverlapped(int start1, int end1, int start2, int end2) {
    return {max(start1, start2), min(end1, end2)};
  }
};