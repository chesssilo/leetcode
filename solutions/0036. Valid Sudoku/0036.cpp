// Time complexity: O(1)
// Space complexity: O(1)
class Solution {
 public:
  bool isValidSudoku(const vector<vector<char>>& board) {
    unordered_set<string> seen;

    for (int i = 0; i < board.size(); ++i)
      for (int j = 0; j < board[0].size(); ++j) {
        if (board[i][j] == '.')
          continue;
        const string c(1, board[i][j]);
        if (!seen.insert(c + "@row" + to_string(i)).second ||
            !seen.insert(c + "@col" + to_string(j)).second ||
            !seen.insert(c + "@box" + to_string(i / 3) + to_string(j / 3))
            .second)
          return false;
      }

    return true;
  }
};