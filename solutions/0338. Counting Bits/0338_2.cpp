// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    vector<int> countBits(const int n) {
        vector<int> ans(n + 1);
        for (int i = 1; i <= n; ++i) {
            ans[i] = ans[i >> 1] + (i & 1);
        }
        return ans;
    }
};