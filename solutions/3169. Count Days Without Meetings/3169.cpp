// Time complexity: O(sort)
// Space complexity: O(sort)
class Solution {
 public:
  int countDays(int days, vector<vector<int>>& meetings) {
    ranges::sort(meetings);
    int workUntil = 0;
    int ans = 0;

    for (const auto& meeting : meetings) {
      if (meeting[0] > workUntil)
        ans += meeting[0] - workUntil - 1;
      workUntil = max(workUntil, meeting[1]);
    }

    return ans + days - workUntil;
  }
};