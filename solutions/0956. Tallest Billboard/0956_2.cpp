// Time complexity: O(n⋅m)
// Space complexity: O(m)
class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        const int sum = accumulate(rods.begin(), rods.end(), 0);
        vector<int> dp(sum + 1, -1);
        dp[0] = 0;

        for (const int h : rods) {
            vector<int> prev(dp);
            for (int i = 0; i <= sum - h; ++i) {
                if (prev[i] < 0)
                    continue;

                dp[i] = max(dp[i], prev[i]);
                dp[i + h] = max(dp[i + h], prev[i]);
                dp[abs(i - h)] = max(dp[abs(i - h)], prev[i] + min(i, h));
            }
        }
        return dp[0];
    }
};