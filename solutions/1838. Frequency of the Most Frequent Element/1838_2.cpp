// Time complexity: O(n*sort)
// Space complexity: O(sort)
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        ranges::sort(nums);
        int left = 0;
        long curr = 0;
        
        for (int right = 0; right < nums.size(); ++right) {
            long target = nums[right];
            curr += target;
            
            if ((right - left + 1) * target - curr > k) {
                curr -= nums[left];
                ++left;
            }
        }
        
        return nums.size() - left;
    }
};