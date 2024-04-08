// Time complexity: O(sort)
// Space complexity: O(sort)
class Solution {
 public:
  long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
    long long ans = 0;

    ranges::sort(nums);
    for (int i = 0; i <= nums.size() / 2; ++i)
      ans += max(0, nums[i] - k);
    for (int i = nums.size() / 2; i < nums.size(); ++i)
      ans += max(0, k - nums[i]);

    return ans;        
  }
};