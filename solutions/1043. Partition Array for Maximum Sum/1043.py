# Time complexity: O(nk)
# Space complexity: O(n)
class Solution:
  def maxSumAfterPartitioning(self, arr: List[int], k: int) -> int:
    n = len(arr)
    maxSum = [0] * (n + 1)

    for start in range(n - 1, -1, -1):
      currMax = 0
      for i in range(start, min(n, start + k)):
        currMax = max(currMax, arr[i])
        maxSum[start] = max(maxSum[start], 
                            maxSum[i + 1] + currMax * (i - start + 1))

    return maxSum[0]        