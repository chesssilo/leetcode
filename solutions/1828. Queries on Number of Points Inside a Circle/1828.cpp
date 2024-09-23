// Time complexity: O(mn)
// Space complexity: O(m)
class Solution {
 public:
  vector<int> countPoints(
    const vector<vector<int>>& points, 
    const vector<vector<int>>& queries
  ) {
    vector<int> ans;

    for (const vector<int>& query : queries) {
      const int xj = query[0];
      const int yj = query[1];
      const int rj = query[2];
      int count = 0;

      for (const vector<int>& point : points) {
        const int xi = point[0];
        const int yi = point[1];

        if (squared(xi - xj) + squared(yi - yj) <= squared(rj))
          ++count;
      }
      ans.push_back(count);
    }

    return ans;
  }

 private:
  int squared(int x) {
    return x * x;
  }
};