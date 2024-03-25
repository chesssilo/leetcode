// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  char findTheDifference(string_view s, string_view t) {
    const char sXors = accumulate(s.begin(), s.end(), 0, bit_xor<>());
    const char tXors = accumulate(t.begin(), t.end(), 0, bit_xor<>());
    return sXors ^ tXors;
  }
};