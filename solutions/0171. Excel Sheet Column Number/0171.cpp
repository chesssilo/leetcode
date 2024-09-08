// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  int titleToNumber(string_view columnTitle) {
    return accumulate(
      columnTitle.begin(), columnTitle.end(), 0,
      [](int subtotal, char c) { return subtotal * 26 + (c - 'A' + 1); });
  }
};