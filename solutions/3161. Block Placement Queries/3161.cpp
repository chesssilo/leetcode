// Time complexity: O((|queries| + |blocks|) * log(50001))
// Space complexity: O(50001 + |queries| + |blocks|)
class Solution {
 public:
  vector<bool> getResults(const vector<vector<int>>& queries) {
    vector<bool> ans;
    set<int> obstacles{0};

    for (const auto &query : queries)
      if (query[0] == 1)
        obstacles.insert(query[1]);

    for (auto it = next(begin(obstacles)); it != end(obstacles); ++it)
      updateBlockSize(*it, *it - *prev(it));

    for (int i = queries.size() - 1; i >= 0; --i) {
      int type = queries[i][0];
      int pos = queries[i][1];
      int blockSize = type == 1 ? 0 : queries[i][2];
      auto obstacleIt = obstacles.lower_bound(pos);

      if (type == 1) {
        if (next(obstacleIt) != end(obstacles))
          updateBlockSize(*next(obstacleIt), *next(obstacleIt) - 
                                             *prev(obstacleIt));
        obstacles.erase(obstacleIt);
      } else {
        bool canPlace = pos - *prev(obstacleIt) >= blockSize || 
                        getMaxBlockSize(pos) >= blockSize;
        ans.push_back(canPlace);
      }
    }

    return vector<bool>(rbegin(ans), rend(ans));
  }

 private:
  int blockSizeBIT[50001] = {};

  int getMaxBlockSize(int right) {
    int maxBlockSize = 0;

    for (; right >= 0; right = (right & (right + 1)) - 1)
      maxBlockSize = max(maxBlockSize, blockSizeBIT[right]);

    return maxBlockSize;
  }

  void updateBlockSize(int index, int value) {
    for (; index < 50001; index = index | (index + 1))
      blockSizeBIT[index] = max(blockSizeBIT[index], value);
  }
};