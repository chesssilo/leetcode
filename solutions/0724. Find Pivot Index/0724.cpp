// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int pivotIndex(const vector<int>& nums) {
        const int sum = accumulate(nums.begin(), nums.end(), 0);
        int prefix = 0;

        for (int i = 0; i < nums.size(); ++i) {
            if (prefix == sum - prefix - nums[i]) {
                return i;
            }
            prefix += nums[i];
        }

        return -1;
    }
};