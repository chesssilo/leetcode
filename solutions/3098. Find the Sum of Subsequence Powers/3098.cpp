// Time complexity: O(n^2 * logn)
// Space complexity: O(n^2)
class Solution {
 public:
  int sumOfPowers(vector<int>& nums, int k) {
    long long ans = 0;
    set<int> pwrs;
    ranges::sort(nums);

    for (int i = 0; i < nums.size(); ++i)
      for (int j = i + 1; j < nums.size(); ++j)
        if (nums[i] != nums[j] && pwrs.insert(nums[j] - nums[i]).second) {
          memset(dp, 255, sizeof(dp));
          ans = (ans + dfs(0, nums.size() - 1, k, nums[j] - nums[i], false, nums)) % kMod;
        }

    return ans;
  }
 private:
  int dp[50][50][2];
  int kMod = 1'000'000'007;

  int dfs(int i, int p, int k, int pwr, bool eq, const vector<int>& nums) {
    if (k == 0)
      return eq ? pwr : 0;

    if (i >= nums.size())
      return 0;

    if (dp[p][k][eq] == -1) {
      dp[p][k][eq] = dfs(i + 1, p, k, pwr, eq, nums);
      if (abs(nums[i] - nums[p]) >= pwr)
        dp[p][k][eq] = (dp[p][k][eq] + dfs(i + 1, i, k - 1, pwr, eq | (nums[i] - nums[p] == pwr), nums)) % kMod;
    }

    return dp[p][k][eq];       
  }    
};