// Time complexity: O(target * n)
// Space complexity: O(target) 
class Solution {
public:
    int combinationSum4(const vector<int>& nums, int target) {
        vector<unsigned int> ways(1 + target, 0);
        vector<bool> filled(1 + target, false);
        return getWays(nums, target, ways, filled);
    }

    unsigned int getWays(
        const vector<int>& nums,
        int sum,
        vector<unsigned int> &ways,
        vector<bool> &filled
    ) {
        if (sum == 0) {
            return 1;
        }
        if (!filled[sum]) {
            for (int num : nums) {
                if (sum - num >= 0) {
                    ways[sum] += getWays(nums, sum - num, ways, filled);
                }
            }
            filled[sum] = true;
        }
        return ways[sum];
    }
};