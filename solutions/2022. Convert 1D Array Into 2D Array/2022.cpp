// Time complexity: O(mn)
// Space complexity: O(mn)
class Solution {
 public:
  vector<vector<int>> construct2DArray(
    const vector<int>& original, 
    int m, 
    int n
  ) {
    if (original.size() != m * n)
      return {};

    vector<vector<int>> ans(m, vector<int>(n));

    for (int i = 0; i < original.size(); ++i)
      ans[i / n][i % n] = original[i];

    return ans;
  }
};