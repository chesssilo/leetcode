# Time complexity: O(nlog(max(d)))
# Space complexity: O(1)
class Solution:
  def minDays(self, bloomDay: List[int], m: int, k: int) -> int:
    if len(bloomDay) < m * k:
      return -1

    def getBouquetCount(waitingDays: int) -> int:
      bouquetCount = 0
      requiredFlowers = k
      for day in bloomDay:
        if day > waitingDays:
          requiredFlowers = k
        else:
          requiredFlowers -= 1
          if requiredFlowers == 0:
            bouquetCount += 1
            requiredFlowers = k

      return bouquetCount

    l = min(bloomDay)
    r = max(bloomDay)

    while l < r:
      mid = l + (r - l) // 2
      if getBouquetCount(mid) >= m:
        r = mid
      else:
        l = mid + 1

    return l