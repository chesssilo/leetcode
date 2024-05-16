// Time complexity: O(mn)
// Space complexity: O(1)
class Solution {
 public:
  bool satisfiesConditions(const vector<vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j) {
        if (j < n - 1 && grid[i][j] == grid[i][j + 1])
          return false;
        if (i < m - 1 && grid[i][j] != grid[i + 1][j])
          return false;
      }

    return true;
  }
};