// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int missingNumber(const vector<int>& nums) {
        int n = (int)nums.size();
        long long sum = n * (n + 1LL) / 2;
        for (int num : nums) {
            sum -= num;
        }
        return (int)sum;
    }

};