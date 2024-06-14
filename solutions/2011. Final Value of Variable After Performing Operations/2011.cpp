// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  int finalValueAfterOperations(const vector<string>& operations) {
		int ans = 0;

		for (const string& op : operations)
			ans += op[1] == '+' ? 1 : -1;

		return ans;
  }
};