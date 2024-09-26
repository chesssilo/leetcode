# Time complexity: O(1)
# Space complexity: O(n)
class MyHashMap:
  def __init__(self) -> None:
    self.kSize = 100000
    self.lists = [[] for _ in range(self.kSize)]

  def put(self, key: int, value: int) -> None:
    index = key % self.kSize

    for pair in self.lists[index]:
      if pair[0] == key:
        pair[1] = value
        return

    self.lists[index].append([key, value])

  def get(self, key: int) -> int:
    index = key % self.kSize

    for pair in self.lists[index]:
      if pair[0] == key:
        return pair[1]

    return -1

  def remove(self, key: int) -> None:
    index = key % self.kSize
    self.lists[index] = [pair for pair in self.lists[index] if pair[0] != key]