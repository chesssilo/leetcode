# Time complexity: O(n)
# Space complexity: O(1)
class Solution:
  def winnerOfGame(self, colors: str) -> bool:
    countAlice = 0
    countBob = 0

    for a, b, c in zip(colors, colors[1:], colors[2:]):
      if 'A' == a == b == c:
        countAlice += 1
      elif 'B' == a == b == c:
        countBob += 1   

    return countAlice > countBob 