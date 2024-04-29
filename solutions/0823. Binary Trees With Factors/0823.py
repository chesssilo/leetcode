# Time complexity: O(n^2)
# Space complexity: O(n)
class Solution:
  def numFactoredBinaryTrees(self, arr: List[int]) -> int:
    kMod = 1_000_000_007
    n = len(arr)
    dp = [1] * n
    arr.sort()
    numToIndex = {a: i for i, a in enumerate(arr)}

    for i, root in enumerate(arr):
      for j in range(i):
        if root % arr[j] == 0:
          right = root // arr[j]
          if right in numToIndex:
            dp[i] += dp[j] * dp[numToIndex[right]]
            dp[i] %= kMod

    return sum(dp) % kMod        