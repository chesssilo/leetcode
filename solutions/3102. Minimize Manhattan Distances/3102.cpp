// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  int minimumDistance(const vector<vector<int>>& points) {
    auto [_, i, j] = maxDistance(points);
    return min(maxDistance(points, i)[0], maxDistance(points, j)[0]);
  }

 private:
  array<long long, 3> maxDistance(const vector<vector<int>>& points, int skip = -1) {
    int sumMin = INT_MAX, sumMax = INT_MIN;
    int sumMinIndex = 0, sumMaxIndex = 0;
    int diffMin = INT_MAX, diffMax = INT_MIN;
    int diffMinIndex = 0, diffMaxIndex = 0;

    for (int index = 0; index < points.size(); ++index) {
      const auto& point = points[index];
      int x = point[0];
      int y = point[1];

      if (index == skip)
        continue;

      int sum = x + y;
      int diff = x - y;

      if (sum < sumMin) {
        sumMin = sum;
        sumMinIndex = index;
      }
      if (sum > sumMax) {
        sumMax = sum;
        sumMaxIndex = index;
      }
      if (diff < diffMin) {
        diffMin = diff;
        diffMinIndex = index;
      }
      if (diff > diffMax) {
        diffMax = diff;
        diffMaxIndex = index;
      }
    }

    if (sumMax - sumMin > diffMax - diffMin)
      return {sumMax - sumMin, sumMinIndex, sumMaxIndex};
    return {diffMax - diffMin, diffMinIndex, diffMaxIndex};
  }
};