// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int maxi = nums[0];
        int last = -1;

        for (int i = 0; i < nums.size(); ++i) {
            maxi = max(maxi, nums[i]);
            if (nums[i] < maxi) {
                last = i;
            } 
        }

        if (last == -1) {
            return 0;
        }

        int mini = nums.back();
        int first = -1;
        for (int i = nums.size() - 1; i >= 0; --i) {
            mini = min(mini, nums[i]);
            if (nums[i] > mini) {
                first = i;
            }
        }

        return last - first + 1;
    }
};