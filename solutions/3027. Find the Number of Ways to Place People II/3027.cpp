// Time complexity: O(n^2)
// Space complexity: O(1)
class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](const auto &p1, const auto &p2){
            return p1[0] == p2[0] ? p1[1] > p2[1] : p1[0] < p2[0];
        });
        
        int ans = 0;
        int n = points.size();
        
        for (int i = 0; i < n; ++i) {
            int maxY = INT_MIN;
            for (int j = i + 1; j < n; ++j) {
                if (points[i][1] >= points[j][1] && points[j][1] > maxY) {
                    ++ans;
                    maxY = points[j][1];
                }
            }
        }
        
        return ans;
    }
};