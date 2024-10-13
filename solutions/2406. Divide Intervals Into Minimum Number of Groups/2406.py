# Time complexity: O(nlogn)
# Space complexity: O(n)
class Solution:
  def minGroups(self, intervals: List[List[int]]) -> int:
    minHeap = []

    for left, right in sorted(intervals):
      if minHeap and left > minHeap[0]:
        heapq.heappop(minHeap)
      heapq.heappush(minHeap, right)

    return len(minHeap)