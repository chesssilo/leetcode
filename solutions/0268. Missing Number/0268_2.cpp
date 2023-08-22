// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = (int)nums.size();
        for (int i = 0; i < n; ++i) {
            while (nums[i] != n && nums[i] != i) {
                swap(nums[i], nums[nums[i]]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] == n) {
                return i;
            }
        }
        return n;
    }
};