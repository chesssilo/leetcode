// Time complexity: O(sort)
// Space complexity: O(1)
class Solution {
 public:
  int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
    ranges::sort(points);
    int ans = 0;
    int idx = -1;

    for (const vector<int>& point : points)
      if (point[0] > idx) {
        ++ans;
        idx = point[0] + w;
      }

    return ans;    
  }
};