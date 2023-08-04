// Time complexity: O(1)
// Space complexity: O(1)
class Solution {
public:
  int findComplement(int num) {
    int ans = 0;
    int mask = 1;

    while (num > 0) {
      if ((num & mask) == 0) {
        ans |= mask;
      } else {
        num ^= mask;
      }
      mask <<= 1;
    }
    return ans;
  }
};