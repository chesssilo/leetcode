// Time complexity: O(⁡n)
// Space complexity: O(1)
class Solution {
 public:
  bool lemonadeChange(const vector<int>& bills) {
    int count5 = 0;
    int count10 = 0;

    for (const int bill : bills) {
      if (bill == 5) {
        ++count5;
      } else if (bill == 10) {
        --count5;
        ++count10;
      } else {
        if (count10 > 0) {
          --count10;
          --count5;
        } else {
          count5 -= 3;
        }
      }
      if (count5 < 0)
        return false;
    }

    return true;
  }
};