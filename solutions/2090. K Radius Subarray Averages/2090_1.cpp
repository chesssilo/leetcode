// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if (k == 0) {
            return nums;
        }

        const int n = nums.size();
        const int windows = 2 * k + 1;
        vector<int> result(n, -1);

        if (windows > n) {
            return result;
        }

        vector<long long> prefix(n + 1);
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }

        for (int i = k; i < (n - k); ++i) {
            int leftBound = i - k, rightBound = i + k;
            long long subArraySum = prefix[rightBound + 1] - prefix[leftBound];
            int average = subArraySum / windows;
            result[i] = average;
        }

        return result;
    }
};