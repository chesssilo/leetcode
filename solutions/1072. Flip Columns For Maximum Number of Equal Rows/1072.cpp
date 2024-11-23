// Time complexity: O(mn)
// Space complexity: O(mn)
class Solution {
 public:
  int maxEqualRowsAfterFlips(const vector<vector<int>>& matrix) {
    int ans = 0;
    unordered_map<string, int> patternFrequency;

    for (auto& row : matrix) {
      string patternBuilder = "";

      for (int col = 0; col < row.size(); col++)
        if (row[0] == row[col])
          patternBuilder += "T";
        else
          patternBuilder += "F";
      patternFrequency[patternBuilder]++;
    }

    for (auto& entry : patternFrequency)
      ans = max(entry.second, ans);

    return ans;
  }
};