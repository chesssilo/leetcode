// Time complexity: O(n^2)
// Space complexity: O(n)
class Solution {
 public:
  bool repeatedSubstringPattern(const string& s) {
    const string ss = s + s;
    return ss.substr(1, ss.length() - 2).find(s) != string::npos;
  }
};