# Time complexity: O(1)
# Space complexity: O(n)
class CustomStack:
  def __init__(self, maxSize) -> None:
    self._stack = [0] * maxSize
    self._increments = [0] * maxSize
    self._topIndex = -1

  def push(self, x: int) -> None:
    if self._topIndex < len(self._stack) - 1:
      self._topIndex += 1
      self._stack[self._topIndex] = x

  def pop(self) -> int:
    if self._topIndex < 0:
      return -1

    result = self._stack[self._topIndex] + self._increments[self._topIndex]

    if self._topIndex > 0:
      self._increments[self._topIndex - 1] += self._increments[self._topIndex]

    self._increments[self._topIndex] = 0
    self._topIndex -= 1

    return result

  def increment(self, k: int, val: int) -> None:
    if self._topIndex >= 0:
      index = min(self._topIndex, k - 1)
      self._increments[index] += val