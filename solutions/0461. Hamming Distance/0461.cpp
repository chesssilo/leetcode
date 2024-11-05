// Time complexity: O(1)
// Space complexity: O(1)
class Solution {
 public:
  int hammingDistance(int x, int y) {
    return __builtin_popcount(x ^ y);
  }
};