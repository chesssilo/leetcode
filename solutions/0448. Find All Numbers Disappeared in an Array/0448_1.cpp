// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        for (int num : nums) {
            int i = abs(num) - 1;
            if (nums[i] > 0) {
                nums[i] = -nums[i];
            }
        }
        for (int j = 1; j <= nums.size(); ++j) {
            int i = j - 1;
            if (nums[i] > 0) {
                ans.push_back(j);
            }
        }
        return ans;
    }
};