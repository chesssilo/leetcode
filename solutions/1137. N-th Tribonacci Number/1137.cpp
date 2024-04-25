// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  int tribonacci(const int& n) {
    if (n <= 2)
      return n == 0 ? 0 : 1;

    int a = 0, b = 1, c = 1;
    for (int i  = 3; i <= n; ++i) {
      const int t =  a + b + c;
      a = b;
      b = c;
      c = t;
    }

    return c;
  }
};