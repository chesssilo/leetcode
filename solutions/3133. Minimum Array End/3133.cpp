// Time complexity: O(1)
// Space complexity: O(1)
class Solution {
 public:
  long long minEnd(int n, int x) {
    n -= 1;
    long long temp = 1;

    for (int i = 0; i < 64; ++i) {
      if ((temp & x) == 0) {
        x |= (n & 1) * temp;
        n >>= 1;
      }
      temp <<= 1;
    }

    return x;
  }
};