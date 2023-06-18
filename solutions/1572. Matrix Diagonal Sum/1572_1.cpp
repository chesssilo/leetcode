// Time complexity: O(n^2)
// Space complexity: O(1)
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0;
        for (int i = 0; i < size(mat); i++) {
            for (int j = 0; j < size(mat[i]); j++) {
                if (i == j) {
                    sum += mat[i][j];
                }
                int temp = size(mat[i]);
                if (j == (size(mat[i]) -  i - 1) && i != j) {
                    sum += mat[i][j];
                }
            }
        }
        return sum;
    }
};