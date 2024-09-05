// Time Complexity: O(m+n)
// Space Complexity: O(n)
class Solution {
 public:
  int robotSim(
    const vector<int>& commands, 
    const vector<vector<int>>& obstacles
  ) {
    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int ans = 0;
    int x = 0;
    int y = 0;
    int d = 0;

    set<pair<int, int>> obstacleSet;
    for (const auto& obs : obstacles) {
      obstacleSet.insert({obs[0], obs[1]});
    }

    for (int command : commands) {
      if (command == -2) {
        d = (d + 3) % 4;
      } else if (command == -1) {
        d = (d + 1) % 4;
      } else {
        for (int i = 0; i < command; ++i) {
          int nextX = x + dirs[d].first;
          int nextY = y + dirs[d].second;
          if (obstacleSet.find({nextX, nextY}) == obstacleSet.end()) {
            x = nextX;
            y = nextY;
            ans = max(ans, x * x + y * y);
          } else {
            break;
          }
        }
      }
    }

    return ans;
  }
};