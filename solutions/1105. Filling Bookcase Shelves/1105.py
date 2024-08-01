# Time complexity: O(n^2)
# Space complexity: O(n)
class Solution:
  def minHeightShelves(self, books: List[List[int]], shelfWidth: int) -> int:
    dp = [0] + [math.inf] * len(books)

    for i in range(len(books)):
      sumThikness = 0
      maxHeight = 0
      for j in range(i, -1, -1):
        thickness, height = books[j]
        sumThikness += thickness
        if sumThikness > shelfWidth:
          break
        maxHeight = max(maxHeight, height)
        dp[i + 1] = min(dp[i + 1], dp[j] + maxHeight)

    return dp[-1]