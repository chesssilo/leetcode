// Time complexity: O(target * n)
// Space complexity: O(target) 
class Solution {
public:
    int combinationSum4(const vector<int>& nums, int target) {
        vector<unsigned int> ways(1 + target, 0);
        ways[0] = 1;
        for (int sum = 1; sum <= target; ++sum) {
            for (int num : nums) {
                if (sum - num >= 0) {
                    ways[sum] += ways[sum - num];
                }
            }
        }
        return (int)ways[target];
    }
};