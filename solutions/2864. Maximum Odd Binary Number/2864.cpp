// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  string maximumOddBinaryNumber(string_view s) {
    const int zeros = ranges::count(s, '0');
    const int ones = s.length() - zeros;
    return string(ones - 1, '1') + string(zeros, '0') + '1';
  }
};