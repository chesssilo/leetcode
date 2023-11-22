// Time complexity: O(nlogn)
// Space complexity: O(1)
class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        ranges::sort(nums);
        int l = 0;
        int r = nums.size() - 1;
        int count = 0;

        while(l < r) {
            if (nums[l] + nums[r] == k) {
                count++;
                l++;
                r--;
            }
            if (nums[l] + nums[r] > k) {
                r--;
            }
            if (nums[l] + nums[r] < k) {
                l++;
            }
        }
        return count;   
    }
};