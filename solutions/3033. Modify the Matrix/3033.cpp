// Time complexity: O(mn)
// Space complexity: O(1)
class Solution {
public:
  vector<vector<int>> modifiedMatrix(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    for (int i = 0; i < cols; ++i) {
      int maxVal = 0;
      for (int j = 0; j < rows; ++j)
        maxVal = max(maxVal, matrix[j][i]);

      for (int j = 0; j < rows; ++j) {
        if (matrix[j][i] == -1)
          matrix[j][i] = maxVal;
      }
    }

    return matrix;
  }
};