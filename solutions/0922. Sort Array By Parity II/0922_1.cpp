// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
	vector<int> sortArrayByParityII(vector<int>& nums) {
		vector<int> res(nums.size());
		int even = 0;
		int odd = 1;
		for (int e : nums) {
			if ((e & 1) == 0) {
				res[even] = e;
				even += 2;
			} else {
				res[odd] = e;
				odd += 2;
			}
		}
		return res;
	}
};