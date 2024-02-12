// Time complexity: O(nlogn)
// Space complexity: O(1)
class Solution {
public:
  int majorityElement(vector<int>& nums) {
		ranges::sort(nums);
    return nums[nums.size() / 2];
  }
};