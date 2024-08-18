// Time complexity: O(mn)
// Space complexity: O(n)
class Solution {
 public:
  long long maxPoints(const vector<vector<int>>& points) {
    const int n = points[0].size();
    vector<long> dp(n);

    for (const vector<int>& row : points) {
      vector<long> leftToRight(n);
      long runningMax = 0;

      for (int j = 0; j < n; ++j) {
        runningMax = max(runningMax - 1, dp[j]);
        leftToRight[j] = runningMax;
      }

      vector<long> righToLeft(n);
      runningMax = 0;

      for (int j = n - 1; j >= 0; --j) {
        runningMax = max(runningMax - 1, dp[j]);
        righToLeft[j] = runningMax;
      }

      for (int j = 0; j < n; ++j)
        dp[j] = max(leftToRight[j], righToLeft[j]) + row[j];
    }

    return ranges::max(dp);
  }
};