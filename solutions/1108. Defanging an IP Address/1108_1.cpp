// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  string defangIPaddr(string address) {
    return regex_replace(address, regex("[.]"), "[.]");
  }
};