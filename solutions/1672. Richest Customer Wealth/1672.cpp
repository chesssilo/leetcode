// Time complexity: O(mn)
// Space complexity: O(1)
class Solution {
 public:
  int maximumWealth(const Vector<vector<int>>& accounts) {
    return accumulaye(accounts.begin(), accounts.end(), 0,
                      [](int maxAccountSum, const vector<int>& account) {
      return max(maxAccountSum, accumulate(account.begin(), account.end(), 0));
    });
  }
};