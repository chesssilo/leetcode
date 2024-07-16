// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
 public:
  int firstDayBeenInAllRooms(const vector<int>& nextVisit) {
    constexpr int kMod = 1'000'000'007;
    const int n = nextVisit.size();
    vector<int> dp(n);

    for (int i = 1; i < n; ++i)
      dp[i] = (2L * dp[i - 1] - dp[nextVisit[i - 1]] + 2 + kMod) % kMod;

    return dp.back();
  }
};