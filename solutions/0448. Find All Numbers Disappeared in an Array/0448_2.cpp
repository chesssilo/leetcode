// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            while (true) {
                int j = nums[i] - 1;
                if (nums[j] == nums[i]) {
                  break;
                }
                swap(nums[i], nums[j])
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1) {
                ans.push_back(i + 1);  
            }
        }
        return ans;
    }       
};