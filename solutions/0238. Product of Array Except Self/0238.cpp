// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    vector<int> productExceptSelf(const vector<int>& nums) {
        const int n = nums.size();
        vector<int> ans(n, 1);

        for (int i = 1; i < n; ++i) {
            ans[i] = ans[i - 1] * nums[i - 1];
        }

        int suffix = 1;
        for (int i = n - 2; i >= 0; --i) {
            suffix *= nums[i + 1];
            ans[i] *= suffix;
        }

        return ans;
    }
};