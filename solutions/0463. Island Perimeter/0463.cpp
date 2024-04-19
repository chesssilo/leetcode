// Time complexity: O(mn)
// Space complexity: O(1)
class Solution {
 public:
  int islandPerimeter(const vector<vector<int>>& grid) {
    int ans = 0;
    for (int i = 0; i < grid.size(); ++i)
      for (int j = 0; j < grid[0].size(); ++j)
        if (grid[i][j] == 1) { 
          ans += (i == 0 || grid[i - 1][j] == 0);
          ans += (j == 0 || grid[i][j - 1] == 0);
        }

    return 2 * ans;
  }
};