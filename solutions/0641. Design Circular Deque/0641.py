# Time complexity: O(1)
# Space complexity: O(k)
class MyCircularDeque:
  def __init__(self, k: int) -> None:
    self.k = k
    self.q = [0] * k
    self.size = 0
    self.front = 0
    self.rear = k - 1

  def insertFront(self, value: int) -> bool:
    if self.isFull():
      return False

    self.front = (self.front - 1 + self.k) % self.k
    self.q[self.front] = value
    self.size += 1

    return True

  def insertLast(self, value: int) -> bool:
    if self.isFull():
      return False

    self.rear = (self.rear + 1) % self.k
    self.q[self.rear] = value
    self.size += 1

    return True

  def deleteFront(self) -> bool:
    if self.isEmpty():
      return False

    self.front = (self.front + 1) % self.k
    self.size -= 1

    return True

  def deleteLast(self) -> bool:
    if self.isEmpty():
      return False

    self.rear = (self.rear - 1 + self.k) % self.k
    self.size -= 1

    return True

  def getFront(self) -> int:
    return -1 if self.isEmpty() else self.q[self.front]

  def getRear(self) -> int:
    return -1 if self.isEmpty() else self.q[self.rear]

  def isEmpty(self) -> bool:
    return self.size == 0

  def isFull(self) -> bool:
    return self.size == self.k