// Time complexity: O(n+edges+query)
// Space complexity: O(n+edges+query)
class Solution {
 public:
  vector<int> minimumCost(int n, const vector<vector<int>> & edges, const vector<vector<int>>& query) {
    vector<vector<int>> adj(n);
    constexpr int MAX_COST = (1 << 30) - 1;
    vector<int> c(n, MAX_COST);

    for (const auto& edge: edges) {
      int u = edge[0];
      int v = edge[1];
      int k = edge[2];
      adj[u].emplace_back(v);
      adj[v].emplace_back(u);
      c[u] &= k;
      c[v] &= k;
    }

    queue<int> q;
    vector<int> group(n, -1);
    for (int i = 0; i < n; ++i) {
      if (group[i] == -1) {
        group[i] = i;
        q.push(i);
        while (!q.empty()) {
          int u = q.front();
          q.pop();
          c[i] &= c[u];
          for (int v : adj[u]) {
            if (group[v] == -1) {
              group[v] = i;
              q.push(v);
            }
          }
        }
      }
    }

    vector<int> ans;
    for (const auto& que : query) {
      int s = que[0];
      int t = que[1];
      if (s == t) {
        ans.emplace_back(0);
      } else {
        if (group[s] == group[t]) {
          ans.emplace_back(c[group[s]]);
        } else {
          ans.emplace_back(-1);
        }
      }
    }

    return ans;
  }
};