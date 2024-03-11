// Time complexity: O(nk)
// Space complexity: O(nk)
class Solution {
 public:
  long long maximumStrength(vector<int>& nums, int k) {
    dp = vector<vector<vector<long long>>>(nums.size(),
          vector<vector<long long>>(k + 1,
          vector<long long>(2, -1e16)));

    long long ans = -1e15;
    return solve(0, static_cast<long long>(k), false, nums);
  }

 private:
  vector<vector<vector<long long>>> dp;

  long long solve(int i, long long k, bool started, vector<int>& nums) {
    if (k == 0)
      return 0;

    if (i == nums.size()) {
      if (k == 1 && started)
        return 0;
      return -1e15;
    }

    if (dp[i][k][started] != -1e16)
      return dp[i][k][started];

    long long ans = -1e15;

    if (started)
      ans = solve(i, k - 1, false, nums);

    ans = max((k % 2 == 0 ? -1 : 1) * k * nums[i] + 
          solve(i + 1, k, true, nums), ans);

    if (!started)
      ans = max(solve(i + 1, k, false, nums), ans);

    return dp[i][k][started] = ans;
  }
};