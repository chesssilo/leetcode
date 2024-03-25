// Time complexity: O(1)
// Space complexity: O(1)
class Solution {
 public:
  int minOperations(int k) {
    int a = sqrt(k);
    return a + (k - 1) / a - 1;
  }
};