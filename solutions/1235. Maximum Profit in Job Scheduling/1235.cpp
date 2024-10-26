// Time complexity: O(sort)
// Space complexity: O(n)
class Solution {
 public:
  int jobScheduling(
    const vector<int>& startTime, 
    const vector<int>& endTime, 
    const vector<int>& profit
  ) {
    int numJobs = profit.size();
    vector<tuple<int, int, int>> jobs(numJobs);

    for (int i = 0; i < numJobs; ++i)
      jobs[i] = {endTime[i], startTime[i], profit[i]};

    ranges::sort(jobs);
    vector<int> dp(numJobs + 1);

    for (int i = 0; i < numJobs; ++i) {
      auto [endTime, startTime, profit] = jobs[i];

      int latestNonConflictJobIndex = 
        upper_bound(jobs.begin(), jobs.begin() + i, startTime, 
          [&](int time, const auto& job) -> bool {
            return time < get<0>(job);
          }) - jobs.begin();

      dp[i + 1] = max(dp[i], dp[latestNonConflictJobIndex] + profit);
    }

    return dp[numJobs];
  }
};