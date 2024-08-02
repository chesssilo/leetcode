// Time complexity: O(nm)
// Space complexity: O(nm)
class Solution {
 public:
  int longestCommonSubsequence(string_view text1, string_view text2) {
    const int n = text1.length();
    const int m = text2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        dp[i + 1][j + 1] = text1[i] == text2[j]
                               ? dp[i][j] + 1
                               : max(dp[i][j + 1], dp[i + 1][j]);

    return dp[n][m];
  }
};