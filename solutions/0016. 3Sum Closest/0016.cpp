// Time complexity: O(n^2)
// Space complexity: O(1)
class Solution {
public:
  int threeSumClosest(vector<int>& nums, int target) {
    int ans = nums[0] + nums[1] + nums[2];
    const int n = nums.size();

    ranges::sort(nums);

    for (int i = 0; i + 2 < n; ++i) {
      if (i > 0 && nums[i] == nums[i - 1])
        continue;
      int left = i + 1;
      int right = n - 1;
      while (left < right) {
        const int sum = nums[i] + nums[left] + nums[right];
        if (sum == target)
          return sum;
        if (abs(sum - target) < abs(ans - target))
          ans = sum;
        if (sum < target)
          ++left;
        else
          --right;
      }
    }

    return ans;
  }
};