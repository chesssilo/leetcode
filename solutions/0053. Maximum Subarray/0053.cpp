// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  int maxSubArray(const vector<int>& nums) {
    int currentSum = nums[0];
    int maxSum = nums[0];

    for (int i = 1; i < nums.size(); ++i) {
      currentSum = max(nums[i], currentSum + nums[i]);
      maxSum = max(maxSum, currentSum);
    }

    return maxSum;
  }
};