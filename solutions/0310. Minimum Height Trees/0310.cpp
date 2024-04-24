// Time complexity: O(V+E)
// Space complexity: O(V+E)
class Solution {
 public:
  vector<int> findMinHeightTrees(int n, const vector<vector<int>>& edges) {
    vector<vector<int>> graph(n);
    vector<int> degree(n, 0);

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      graph[u].push_back(v);
      graph[v].push_back(u);
      degree[u]++;
      degree[v]++;
    }

    vector<int> leaves;
    for (int i = 0; i < n; ++i)
      if (degree[i] <= 1)
        leaves.push_back(i);

    while (n > 2) {
      vector<int> next_leaves;

      for (const int& u : leaves) {
        for (const int& v : graph[u]) {
          degree[v]--;
          if (degree[v] == 1)
            next_leaves.push_back(v);
        }
        n--;
      }
      leaves = next_leaves;
    }

    return leaves;
  }
};