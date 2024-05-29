// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
 public:
  vector<int> queryResults(int limit, const vector<vector<int>>& queries) {
    unordered_map<int, int> ballToColor;
    unordered_map<int, int> colorCount;
    vector<int> ans;

    for (const vector<int>& query : queries) {
      const int ball = query[0];
      const int color = query[1];
      if (const auto it = ballToColor.find(ball); it != ballToColor.cend()) {
        const int prevColor = it->second;
        if (--colorCount[prevColor] == 0)
          colorCount.erase(prevColor);
      }
      ballToColor[ball] = color;
      ++colorCount[color];
      ans.push_back(colorCount.size());
    }

    return ans;
  }
};