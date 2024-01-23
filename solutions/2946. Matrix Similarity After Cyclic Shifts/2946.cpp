// Time complexity: O(mn)
// Space complexity: O(1)
class Solution {
public:
    bool areSimilar(const vector<vector<int>>& mat, const int k) {
        const int n = mat[0].size();
        for (const vector<int>& row : mat)
            for (int j = 0; j < n; ++j)
                if (row[j] != row[(j + k) % n])
                    return false;

        return true;            
    }
};