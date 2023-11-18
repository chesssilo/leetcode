// Time complexity: O(n*sort)
// Space complexity: O(sort)
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        ranges::sort(nums);
        int left = 0;
        int ans = 0;
        long long curr = 0;
        
        for (int right = 0; right < nums.size(); ++right) {
            long target = nums[right];
            curr += target;
            
            while ((right - left + 1) * target - curr > k) {
                curr -= nums[left];
                ++left;
            }
            
            ans = max(ans, right - left + 1);
        }
        
        return ans;
    }
};