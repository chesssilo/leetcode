// Time complexity: O(mn)
// Space complexity: O(1)
class Solution {
 public:
  int numberOfBeams(const vector<string>& bank) {
    int ans = 0;
    int prevOnes = 0;

    for (const string& row : bank) {
      const int ones = ranges::count(row, '1');
      if (ones > 0) {
        ans += prevOnes * ones;
        prevOnes = ones;
      }
    }

    return ans;
  }
};