// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  int maxPointsInsideSquare(const vector<vector<int>>& points, string_view s) {
    int secondMinSize = INT_MAX;
    vector<int> minSizes(26, INT_MAX);

    for (int i = 0; i < points.size(); ++i) {
      const int x = points[i][0];
      const int y = points[i][1];
      const int sz = max(abs(x), abs(y));
      const int j = s[i] - 'a';
      if (minSizes[j] == INT_MAX) {
        minSizes[j] = sz;
      } else if (sz < minSizes[j]) {
        secondMinSize = min(secondMinSize, minSizes[j]);
        minSizes[j] = sz;
      } else {
        secondMinSize = min(secondMinSize, sz);
      }
    }

    return ranges::count_if(minSizes, 
                            [&](int sz) { return sz < secondMinSize; });
  }
};