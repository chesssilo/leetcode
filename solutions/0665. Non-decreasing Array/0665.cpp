// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool modified = false;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] < nums[i - 1]) {
                if (modified) {
                    return false;
                }
                if (i == 1 || nums[i] >= nums[i - 2]) {
                    nums[i - 1] = nums[i];
                } else {
                    nums[i] = nums[i - 1];
                }
                modified = true;
            }
        }
        return true;
    }
};