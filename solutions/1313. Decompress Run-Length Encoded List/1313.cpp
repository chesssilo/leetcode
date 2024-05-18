// Time complexity: O(nm)
// Space complexity: O(m)
class Solution {
 public:
  vector<int> decompressRLElist(const vector<int>& nums) {
    vector<int> ans;

    for (int i = 0; i < nums.size(); i += 2)
      ans.insert(ans.end(), nums[i], nums[i + 1]);

    return ans;
  }
};