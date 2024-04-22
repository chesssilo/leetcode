// Time complexity: O(rows*cols)
// Space complexity: O(rows*cols)
class Solution {
 public:
  int minimumOperations(const vector<vector<int>>& grid) {
    int rows = grid.size();
    int cols = grid[0].size();

    vector<vector<int>> count(cols, vector<int>(10, 0));

    for (int i = 0; i < cols; ++i)
      for (int j = 0; j < rows; ++j)
        ++count[i][grid[j][i]];

    memset(dp, -1, sizeof(dp));

    int minimumOps = calculateMinimumOperations(0, 10, rows, cols, count);

    return minimumOps;    
  }
 private:
  int dp[1001][11];

  int calculateMinimumOperations(int index, int prev, int rows, int cols, 
                                  vector<vector<int>>& count) {
    if (index >= cols)
      return 0;
    if (dp[index][prev] != -1)
      return dp[index][prev];

    int ans = INT_MAX;

    for (int i = 0; i <= 9; ++i)
      if (i != prev)
        ans = min(ans, rows - count[index][i] + 
                calculateMinimumOperations(index + 1, i, rows, cols, count));

    return dp[index][prev] = ans;        
  }  
};