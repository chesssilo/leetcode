# Time complexity: O(n)
# Space complexity: O(n)
class Solution:
  def queryResults(self, limit: int, queries: List[List[int]]) -> List[int]:
    ballToColor = {}
    colorCount = collections.Counter()
    ans = []

    for ball, color in queries:
      if ball in ballToColor:
        prevColor = ballToColor[ball]
        colorCount[prevColor] -= 1
        if colorCount[prevColor] == 0:
          del colorCount[prevColor]
      ballToColor[ball] = color
      colorCount[color] += 1
      ans.append(len(colorCount))

    return ans