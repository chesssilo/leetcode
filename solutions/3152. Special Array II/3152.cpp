// Time complexity: O(n+m)
// Space complexity: O(n+m)
class Solution {
 public:
  vector<bool> isArraySpecial(
    const vector<int>& nums, const vector<vector<int>>& queries
  ) {
    vector<bool> ans;
    int id = 0;
    vector<int> parityIds = {id};

    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] % 2 == nums[i - 1] % 2)
        ++id;
      parityIds.push_back(id);
    }

    for (const vector<int> query : queries) {
      const int from = query[0];
      const int to = query[1];
      ans.push_back(parityIds[from] == parityIds[to]);
    }

    return ans;
  }
};