// Time complexity: O(logn)
// Space complexity: O(1)
class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0)
      return false;

    int y = x;
    long reversed = 0;

    while (y > 0) {
      reversed = reversed * 10 + y % 10;
      y /= 10;
    }

    return reversed == x;
  }
};