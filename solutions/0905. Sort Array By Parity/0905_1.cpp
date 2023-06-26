// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
	vector<int> sortArrayByParity(vector<int>& nums) {
		vector<int> res;
		res.reserve(nums.size());
        for (int e : nums) {
            if ((e & 1) == 0) {
                res.push_back(e);
            }
        }
        for (int e : nums) {
            if ((e & 1) != 0) {
                res.push_back(e);
            }
        }
        assert(res.size() == nums.size());
        return res;
	}
};