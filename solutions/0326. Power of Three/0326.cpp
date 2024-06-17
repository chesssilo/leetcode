// Time complexity: O(1)
// Space complexity: O(1)
class Solution {
 public:
  bool isPowerOfThree(int n) {
    return n > 0 && static_cast<int>(pow(3, 19)) % n == 0;
  }
};