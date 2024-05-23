// Time complexity: O(n^2)
// Space complexity: O(n)
class Solution {
 public:
  vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
    vector<int> ans;

    for (int i = 0; i < nums.size(); ++i)
      ans.emplace(ans.begin() + index[i], nums[i]);

    return ans;
  }
};