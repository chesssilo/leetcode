// Time complexity: O(n^2)
// Space complexity: O(1)
class Solution {
 public:
  int countPairs(const vector<int>& nums, int target) {
    int ans = 0;

    for (int i = 0; i < nums.size(); ++i)
      for (int j = i + 1; j < nums.size(); ++j)
        if (nums[i] + nums[j] < target)
          ++ans;

    return ans;
  }
};