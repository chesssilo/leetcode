// Time complexity: O(mn)
// Space complexity: O(m+n)
class Solution {
 public:
  long long numberOfRightTriangles(const vector<vector<int>>& grid) {
    const int n = grid.size();
    const int m = grid[0].size();
    vector<int> dp1(n, 0);
    vector<int> dp2(m, 0);

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        if (grid[i][j] == 1) {
          ++dp1[i];
          ++dp2[j];
        }
        
    long long ans = 0;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        if (grid[i][j] == 1)
          ans += (dp1[i] - 1) * (dp2[j] - 1);

    return ans;
  }
};