// Time complexity : O(m*n)
// Space complexity : O(1)
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        for (auto iter : grid)
            for (int i : iter)
                if (i < 0) count++;

        return count;
    }
};