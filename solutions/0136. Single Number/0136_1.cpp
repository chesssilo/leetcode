// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;

        for (const int num : nums)
            ans ^= num;

        return ans;
    }
};