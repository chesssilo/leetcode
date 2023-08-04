// Time complexity: O(1)
// Space complexity: O(1)
class Solution {
public:
  int findComplement(int num) {
    int left = 0;
    int right = 31;

    while (right > left + 1) {
      int mid = (left + right) >> 1;
      if ((1 << mid) > num) {
        right = mid;
      } else {
        left = mid;
      }
    }
    int mask = (1 << left) + ((1 << left) - 1);
    return num ^ mask;
  }
};