class Solution {
 public:
  int numberOfStableArrays(int zero, int one, int limit) {
    const int kMod = 1'000'000'007;
    int dp[zero + 1][one + 1][2];

    for (int i = 0; i <= zero; ++i) {
      for (int j = 0; j <= one; ++j) {
        dp[i][j][0]= 0;
        dp[i][j][1] = 0;

        if (i == 0 || j == 0) {
          if (0 < i && i <= limit)
            dp[i][j][0] = 1;
          if (0 < j && j <= limit)
            dp[i][j][1] = 1;

          continue;
        }

        if (i > 0)
          dp[i][j][0] = (dp[i - 1][j][0] + dp[i - 1][j][1]) % kMod;
        if (i - limit > 0)
          dp[i][j][0] = (dp[i][j][0] + kMod - dp[i - 1 - limit][j][1]) % kMod;
        if (j > 0)
          dp[i][j][1] = (dp[i][j - 1][0] + dp[i][j - 1][1]) % kMod;
        if (j - limit > 0)
          dp[i][j][1] = (dp[i][j][1] + kMod - dp[i][j - 1 - limit][0]) % kMod;      
      }
    }
    dp[zero][one][0] = (dp[zero][one][0] + dp[zero][one][1]) % kMod;

    return dp[zero][one][0];
  }
};