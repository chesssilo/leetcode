// Time complexity: O(1)
// Space complexity: O(1)
class Solution {
 public:
  bool canMakeSquare(const vector<vector<char>>& grid) {
    for (int i = 0; i < grid.size() -  1; ++i)
      for (int j = 0; j < grid[0].size() - 1; ++j) {
        int b = 0, w = 0;
        for (auto& p : vector<pair<int, int>>{{i, j}, {i + 1, j},
                                               {i, j + 1}, {i + 1, j + 1}}) {
          int u = p.first;
          int v = p.second;
          b += int(grid[u][v] == 'B');
          w += int(grid[u][v] == 'W');
        }
        if (b >= 3 || w >= 3)
          return true;
      }

    return false;
  }
};