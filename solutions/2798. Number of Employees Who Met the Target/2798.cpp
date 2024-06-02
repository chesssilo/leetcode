// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  int numberOfEmployeesWhoMetTarget(const vector<int>& hours, int target) {
    int ans = 0;

    for (const int hour : hours)
      if (hour >= target)
        ++ans;

    return ans;
  }
};