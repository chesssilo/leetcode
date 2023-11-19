// Time complexity: O(sort)
// Space complexity: O(sort)
class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        ranges::sort(nums);
        int ans = 0;
        int up = 0;
        
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1]) {
                ++up;
            }
            
            ans += up;
        }
        
        return ans;
    }
};