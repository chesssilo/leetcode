// Time complexity: O(sort)
// Space complexity: O(n)
class Solution {
 public:
  bool isNStraightHand(vector<int>& hand, int groupSize) {
    if (hand.size() % groupSize != 0)
      return false;

    ranges::sort(hand);

    unordered_map<int, int> cardCount;
    for (const int card : hand)
      ++cardCount[card];

    for (const int card : hand) {
      if (cardCount[card] == 0)
        continue;

      for (int i = 0; i < groupSize; ++i)
        if(cardCount[card + i] > 0)
          --cardCount[card + i];
        else
          return false;
    }

    return true;
  }
};