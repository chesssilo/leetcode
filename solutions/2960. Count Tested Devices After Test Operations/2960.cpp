// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  int countTestedDevices(const vector<int>& batteryPercentages) {
    int ans = 0;

    for (const int batteryPercentage : batteryPercentages)
      if (batteryPercentage -  ans > 0)
        ++ans;

    return ans;
  }
};