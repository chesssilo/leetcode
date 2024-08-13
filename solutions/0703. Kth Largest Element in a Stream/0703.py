# Time complexity: O(nlogk)
# Space complexity: O(k)
class KthLargest:
  def __init__(self, k: int, nums: List[int]) -> None:
    self.k = k = k
    self.minHeap = []

    for num in nums:
      self.add(num)

  def add(self, val: int) -> int:
    heapq.heappush(self.minHeap, val)
    if len(self.minHeap) > self.k:
      heapq.heappop(self.minHeap)

    return self.minHeap[0]