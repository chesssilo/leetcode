// Time complexity: O(nlogn)
// Space complexity: O(n)
#define ll long long

class Solution {
public:
    int findMaximumLength(const vector<int>& nums) {
        int n = nums.size();
        vector<ll> prefix(n + 1, 0);

        for (int i = 0; i < n; ++i)
            prefix[i + 1] = prefix[i] + nums[i];

        vector<pair<ll, ll>> dp(n + 1, {0, 0});

        for (int i = 1; i <= n; ++i) {
            auto [len, num] = dp[i - 1];
            num *= -1LL;

            if (num <= nums[i - 1])
                dp[i] = max(dp[i], {len + 1, -1LL * nums[i - 1]});
            else
                dp[i] = max(dp[i], {len, -1LL * (num + nums[i - 1])});

            ll lbneed = prefix[i] - nums[i - 1] + num;
            auto it = lower_bound(prefix.begin(), prefix.end(), lbneed);
            if (it != prefix.end()) {
                int id = distance(prefix.begin(), it);
                dp[id] = max(dp[id], {len + 1, -1LL * (num + prefix[id] - lbneed)});
            }
        }

        return dp[n].first;
    }
};