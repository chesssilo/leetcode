// Time complexity: O(m+n)
// Space complexity: O(1)
class Solution {
 public:
  long long minimumCost(
    string_view source,
    string_view target,
    const vector<char>& original,
    const vector<char>& changed,
    const vector<int>& cost
  ) {
    long ans = 0;
    vector<vector<long>> dist(26, vector<long>(26, LONG_MAX));

    for (int i = 0; i < cost.size(); ++i) {
      const int u = original[i] - 'a';
      const int v = changed[i] - 'a';
      dist[u][v] = min(dist[u][v], static_cast<long>(cost[i]));
    }

    for (int k = 0; k < 26; ++k)
      for (int i = 0; i < 26; ++i)
        if (dist[i][k] < LONG_MAX)
          for (int j = 0; j < 26; ++j)
            if (dist[k][j] < LONG_MAX)
              dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    for (int i = 0; i < source.length(); ++i) {
      if (source[i] == target[i])
        continue;
      const int u = source[i] - 'a';
      const int v = target[i] - 'a';
      if (dist[u][v] == LONG_MAX)
        return -1;
      ans += dist[u][v];
    }

    return ans;
  }
};