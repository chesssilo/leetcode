class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        const long long b = 101;
        const long long p = 1000 * 1000 * 1000 + 7;
        long long prevH = 0;
        const int m = matrix.size();
        const int n = matrix[0].size();

        for (int i = 0; i < m; ++i) {
            long long pow = 1;
            int rowFirst = 0;
            long long h = 0;
            for (int j = 0; j < n; ++j) {
                if (i == 0) {
                    if (j + 1 < n) {
                        h += matrix[i][j] * pow;
                        h %= p;
                        pow *= b;
                        pow %= p;
                    } else {
                        prevH = h;
                    }
                } else {
                    if(j == 0) {
                        rowFirst = matrix[i][j];
                    } else if (j + 1 < n) {
                        h += matrix[i][j] * pow;
                        h %= p;
                        pow *= b;
                        pow %= p;
                    } else {
                        if ((h + matrix[i][j] * pow) % p != prevH) {
                        return false;
                        }
                        prevH = (rowFirst + h * b) % p;
                    }
                }
            }
        }
        return true;    
    }
};