// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  string getSmallestString(string s, int k) {
    for (char &c : s) {
      int l = c - 'a';
      int r = 'z' - c + 1;
      int minDistance = min(l, r);
      if (k >= minDistance) {
        k -= minDistance;
        c = 'a';
      } else {
        c = c - k;
        k = 0;
      }
    }

    return s;
  }
};