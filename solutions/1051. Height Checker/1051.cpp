// Time complexity: O(sort)
// Space complexity: O(n)
class Solution {
 public:
  int heightChecker(const vector<int>& heights) {
    vector<int> expected(heights);
    ranges::sort(expected);
    int ans = 0;

    for (int i = 0; i < heights.size(); ++i)
      if (heights[i] != expected[i])
        ++ans;

    return ans;
  }
};