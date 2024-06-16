# Time complexity: O(nlogn)
# Space complexity: O(n)
class T:
  def __init__(self, pro: int, cap: int):
    self.pro = pro
    self.cap = cap

  def __lt__(self, other):
    return self.cap < other.cap

class Solution:
  def findMaximizedCapital(self, k: int, w: int, profits: List[int], 
                                                 capital: List[int]) -> int:
    minHeap = []
    maxHeap = []

    for i in range(len(capital)):
      heapq.heappush(minHeap, T(profits[i], capital[i]))

    for _ in range(k):
      while minHeap and minHeap[0].cap <= w:
        heapq.heappush(maxHeap, (-minHeap[0].pro, minHeap[0]))
        heapq.heappop(minHeap)
      if not maxHeap:
        break
      w += -heapq.heappop(maxHeap)[0]

    return w