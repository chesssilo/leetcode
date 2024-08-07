// Time complexity: O(logn)
// Space complexity: O(1)
class Solution {
 public:
  int minBitFlips(unsigned start, unsigned goal) {
    return popcount(start ^ goal);
  }
};