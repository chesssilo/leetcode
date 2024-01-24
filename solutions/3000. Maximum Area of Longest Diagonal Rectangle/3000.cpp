// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int areaOfMaxDiagonal(const vector<vector<int>>& dimensions) {
        int maxDiagonal = 0;
        int maxArea = 0;

        for (auto& dimension : dimensions) {
            int length = dimension[0];
            int width = dimension[1];

            int diagonal = sqrt(length * length + width * width);
            int area = length * width;

            if (diagonal > maxDiagonal) {
                maxDiagonal = diagonal;
                maxArea = area;
            }
            else if (diagonal == maxDiagonal && area > maxArea) {
                maxArea = area;
            }
        }

        return maxArea;
    }
};