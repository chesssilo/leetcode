// Time complexity: O(n^3)
// Space complexity: O(1)
class Solution {
 public:
  int equalPairs(const vector<vector<int>>& grid) {
    const int n = grid.size();
    int ans = 0;

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) {
        int k = 0;
        for (; k < n; ++k)
          if (grid[i][k] != grid[k][j])
            break;
        if (k == n)
          ++ans;    
      }

    return ans;  
  }
};