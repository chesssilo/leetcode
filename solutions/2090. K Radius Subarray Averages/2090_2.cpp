// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        const int n = nums.size();
        const int window = 2 * k + 1;
        vector<int> result(n, -1);

        if (window > n) {
            return result;
        }

        long sum = accumulate(nums.begin(), nums.begin() + window, 0L);

        for (int i = k; i + k < n; ++i) {
            result[i] = sum / window;
            if (i + k + 1 < n) {
                sum += nums[i + k + 1] - nums[i - k];
            }
        }
        return result;
    }
};