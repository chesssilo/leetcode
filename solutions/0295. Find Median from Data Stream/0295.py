class MinHeap:
  def __init__(self):
    self.arr = []
  def __len__(self):
    return len(self.arr)
  def top(self):
    if self.arr:
      return self.arr[0]
  def push(self, val):
    heapq.heappush(self.arr, val)
  def pop(self):
    return heapq.heappop(self.arr)

class MaxHeap(MinHeap):
  def push(self, val):
    super().push(-val)
  def top(self):
    return -super().top()
  def pop(self):
    return -super().pop() 

class MedianFinder:

  def __init__(self):
    self.left = MaxHeap()
    self.right = MinHeap()  

  def addNum(self, num: int) -> None:
    self.left.push(num)
    if self.left.top() and self.right.top() and self.left.top() > self.right.top():
      val = self.left.pop()
      self.right.push(val)
    if len(self.right) - len(self.left) > 1:
      val = self.right.pop()
      self.left.push(val) 
    if len(self.left) - len(self.right) > 1:
      val = self.left.pop()
      self.right.push(val)   

  def findMedian(self) -> float:
    if len(self.left) > len(self.right):
      return self.left.top() 
    if len(self.right) > len(self.left):
      return self.right.top()
    return (self.left.top() + self.right.top()) / 2