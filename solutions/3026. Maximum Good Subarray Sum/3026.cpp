// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = LLONG_MIN;
        vector<long long> prefixSum{0};
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); ++i) {
            prefixSum.push_back(prefixSum.back() + nums[i]);
            if (auto it = m.find(nums[i] - k); it != end(m))
                ans = max(ans, prefixSum[i + 1] - prefixSum[it->second]);
            if (auto it = m.find(nums[i] + k); it != end(m))
                ans = max(ans, prefixSum[i + 1] - prefixSum[it->second]);
            if (auto it = m.find(nums[i]); it == end(m) || 
                prefixSum[i] - prefixSum[it->second] <= 0)
                m[nums[i]] = i;
        }
        return ans == LLONG_MIN ? 0 : ans;
    }
};