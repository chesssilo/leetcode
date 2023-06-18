// Time complexity: O(n*m)
// Space complexity: O(1)
class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                int n = nums[i];
                while (n > 0) {
                    result.push_back(nums[i + 1]);
                    n--;
                }
            }
        }
        return result;
    }
};