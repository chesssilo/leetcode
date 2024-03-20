# Time complexity: O(n)
# Space complexity: O(1)
class Solution:
  def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
    count = 0

    for i in range(len(flowerbed)):
      if flowerbed[i] == 0:
        emptyLeftPlot = (i == 0) or (flowerbed[i - 1] == 0)
        emptyRightPlot = (i == len(flowerbed) - 1) or (flowerbed[i + 1] == 0)

        if emptyLeftPlot and emptyRightPlot:
          flowerbed[i] = 1
          count += 1

    return count >= n