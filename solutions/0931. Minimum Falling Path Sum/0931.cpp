// Time complexity: O(n^2)
// Space complexity: O(1)
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        const int n = matrix.size();
        for (int i = 1; i < n; ++i) 
            for (int j = 0; j < n; ++j) {
                int minVal = INT_MAX;
                for (int k = max(0, j - 1); k < min(n, j + 2); ++k)
                    minVal = min(minVal, matrix[i - 1][k]);
                matrix[i][j] += minVal;
            }

        return ranges::min(matrix[n - 1]);    
    }
};