// Time complexity: O(mn)
// Space complexity: O(mn)
class Solution {
 public:
  int minimumObstacles(const vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
    dist[0][0] = 0;
    deque<array<int, 3>> deque;
    deque.push_back({0, 0, 0});

    while (!deque.empty()) {
      auto current = deque.front();
      deque.pop_front();
      int obstacles = current[0], row = current[1], col = current[2];
 
      for (auto& dir : dirs) {
        int newRow = row + dir[0], newCol = col + dir[1];

        if (isValid(grid, newRow, newCol) &&
            dist[newRow][newCol] == INT_MAX) {
          if (grid[newRow][newCol] == 1) {
            dist[newRow][newCol] = obstacles + 1;
            deque.push_back({obstacles + 1, newRow, newCol});
          } else {
            dist[newRow][newCol] = obstacles;
            deque.push_front({obstacles, newRow, newCol});
          }
        }
      }
    }

    return dist[m  -1][n - 1];
  }

 private:
  vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  bool isValid(const vector<vector<int>>& grid, int row, int col) {
    return row >= 0 && col >= 0 && row < grid.size() && col < grid[0].size();
  }
};