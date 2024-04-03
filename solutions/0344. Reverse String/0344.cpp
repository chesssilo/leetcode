// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  void reverseString(vector<char>& s) {
    int l = 0;
    int r = s.size() - 1;

    while (l < r)
      swap(s[l++], s[r--]);
  }
};