// Time complexity: O(n^2)
// Space complexity: O(n)
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;

        ranges::sort(nums);

        for(int i = 0; i + 2 < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int left = i + 1;
            int right = nums.size() - 1;
            while (left < right) {
                const int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    ans.push_back({nums[i], nums[left++], nums[right--]});
                    while (left < right && nums[left] == nums[left - 1])
                        ++left;
                    while (left < right && nums[right] == nums[right + 1])
                        --right;
                } else if (sum < 0) {
                    ++left;
                } else {
                    --right;
                }
            }
        }

        return ans;
    }
};