# Time complexity: O(sort)
# Space complexity: O(n)
class Solution:
  def isNStraightHand(self, hand: List[int], groupSize: int) -> bool:
    if len(hand) % groupSize != 0:
      return False

    cardCount = Counter(hand)
    for card in sorted(hand):
      if cardCount[card] == 0:
        continue

      for i in range(groupSize):
        if cardCount[card + i] > 0:
          cardCount[card + i] -= 1
        else:
          return False

    return True