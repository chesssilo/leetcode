// Time complexity: O(1)
// Space complexity: O(1)
class Solution {
public:
  bool isPowerOfTwo(int n) {
    return n > 0 && (n & (n - 1)) == 0;
  }
};