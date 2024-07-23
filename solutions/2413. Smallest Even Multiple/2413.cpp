// Time complexity: O(1)
// Space complexity: O(1)
class Solution {
 public:
  int smallestEvenMultiple(int n) {
    return n * (n % 2 + 1);
  }
};