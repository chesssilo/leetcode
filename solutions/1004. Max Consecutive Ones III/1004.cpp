// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int longestOnes(const vector<int>& nums, int k) {
        int maxLength = 0;
        int zeroCount = 0;
        int left = 0;
        
        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] == 0) {
                ++zeroCount;
            }
            
            while (zeroCount > k) {
                if (nums[left] == 0) {
                    --zeroCount;
                }
                ++left;
            }
            
            maxLength = max(maxLength, right - left + 1);
        }
        
        return maxLength;
    }
};