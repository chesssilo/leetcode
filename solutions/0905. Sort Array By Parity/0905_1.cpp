// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
	vector<int> sortArrayByParity(vector<int>& nums) {
		vector<int> ans;
		ans.reserve(nums.size());
        for (int num : nums) {
            if ((num & 1) == 0) {
                ans.push_back(num);
            }
        }
        for (int num : nums) {
            if ((num & 1) != 0) {
                ans.push_back(num);
            }
        }
        assert(ans.size() == nums.size());
        return ans;
	}
};