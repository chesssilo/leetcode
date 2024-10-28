// Time complexity: O(d)
// Space complexity: O(1)
class Solution {
 public:
  int subtractProductAndSum(int n) {
    int prod = 1;
    int summ = 0;

    for (; n > 0; n /= 10) {
      prod *= n % 10;
      summ += n % 10;
    }

    return prod - summ;
  }
};