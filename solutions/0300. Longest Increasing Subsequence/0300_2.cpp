// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution {
public:
    int lengthOfLIS(const vector<int>& nums) {
        vector<int> tails(1 + nums.size(), INT_MAX);
        int ans = 0;

        for (const int num : nums) {
            auto it = lower_bound(tails.begin() + 1, tails.end(), num);
            *it = num;
            ans = max(ans, int(it - tails.begin()));
        }

        return ans;
    }
};