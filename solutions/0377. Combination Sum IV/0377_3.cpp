// Time complexity: O(target * n)
// Space complexity: О(min(n, max(target)))
class Solution {
public:
    int combinationSum4(const vector<int>& nums, int target) {
        if (nums.empty()) {
            assert(target > 0);
            return 0;
        }
        int maxNum = 0;
        for (int num : nums) {
            maxNum = max(maxNum, num);
        }
        int size = min(target, maxNum);
        assert(size > 0);
        vector<unsigned int> ways(size, 0);
        ways[0] = 1;
        for (int sum = 1; sum <= target; ++sum) {
            unsigned int s = 0;
            for (int num : nums) {
                if (sum - num >= 0) {
                    s += ways[(sum - num) % size];
                }
            }
            ways[sum % size] = s;
        }
        return (int)ways[target % size];
    }  
};