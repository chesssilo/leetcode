// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        while (n >= 0) {
            ans.push_back(__builtin_popcount(n));
            n--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};