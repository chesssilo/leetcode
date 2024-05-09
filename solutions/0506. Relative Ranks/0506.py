# Time complexity: O(n+m)
# Space complexity: O(n+m)
class Solution:
  def findRelativeRanks(self, score: List[int]) -> List[str]:
    n = len(score)
    m = max(score)

    scoreToIndex = [0] * (m + 1)
    for i in range(n):
      scoreToIndex[score[i]] = i + 1

    MEDALS = ["Gold Medal", "Silver Medal", "Bronze Medal"]

    ans = [""] * n
    place = 1
    for i in range(m, -1, -1):
      if scoreToIndex[i] != 0:
        originalIndex = scoreToIndex[i] - 1
        if place < 4:
          ans[originalIndex] = MEDALS[place - 1]
        else:
          ans[originalIndex] = str(place)

    return ans