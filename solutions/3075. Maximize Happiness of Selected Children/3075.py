# Time complexity: O(nlogn)
# Space complexity: O(1)
class Solution:
  def maximumHappinessSum(self, happiness: List[int], k: int) -> int:
    happiness.sort(reverse=True)
    count = 0
    hSum = 0

    for i in range(k):
      if happiness[i] - count < 0:
        return hSum

      hSum += happiness[i] - count
      count += 1

    return hSum