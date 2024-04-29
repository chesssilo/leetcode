// Time complexity: O(one*zero*limit)
// Space complexity: O(one*zero)
class Solution {
 public:
  int numberOfStableArrays(int zero, int one, int limit) {
    memset(dp, -1, sizeof(dp));
    int a = dfs(zero, one, limit, true) % kMod;
    int b = dfs(zero, one, limit, false) % kMod;

    return (a + b) % kMod;
  }

 private:
  const int kMod = 1'000'000'007;
  int dp[202][202][2];

  int dfs(int zero, int one, int limit, bool ms) {
    if (one == 0 && zero == 0)
      return 1;

    long long res = 0;

    if (dp[one][zero][ms] != -1)
      return dp[one][zero][ms];

    if (ms)
      for (int i = 1; i <= min(one, limit); ++i)
        res += dfs(zero, one - i, limit, false) % kMod;
    else
      for (int i = 1; i <= min(zero, limit); ++i)
        res += dfs(zero - i, one, limit, true) % kMod;

    return dp[one][zero][ms] = res % kMod;
  }
};