# Time complexity: O(n)
# Space complexity: O(1)
class Solution:
  def minimumLevels(self, possible: List[int]) -> int:
    bobScore = 0
    for num in possible:
      bobScore += 1 if num != 0 else -1

    danielScore = 0
    for i in range(len(possible) - 1):
      danielScore += 1 if possible[i] != 0 else -1
      if danielScore > bobScore - danielScore:
        return i + 1

    return -1    