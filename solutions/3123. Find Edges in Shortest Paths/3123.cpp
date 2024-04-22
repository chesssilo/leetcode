// Time complexity: O((n+m)logn)
// Space complexity: O(n+m)
class Solution {
 public:
  vector<bool> findAnswer(int n, const vector<vector<int>>& edges) {
    const int INF = 1'000'000'007;
    vector<vector<pair<int, int>>> graph(n);
    vector<int> dist(n, INF);
    vector<vector<int>> edgeIndex(n);
    vector<bool> ans(edges.size(), false);

    for(int i = 0; i < edges.size(); ++i) {
      const int u = edges[i][0];
      const int v = edges[i][1];
      const int w = edges[i][2];
      graph[u].push_back({v, w});
      graph[v].push_back({u, w});
      edgeIndex[u].push_back(i);
      edgeIndex[v].push_back(i); 
    }

    priority_queue<pair<int, int>, 
                    vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, 0});
    dist[0] = 0;

    while (!pq.empty()) {
      const int u = pq.top().second;
      pq.pop();

      for (int i = 0; i < graph[u].size(); ++i) {
        const int v = graph[u][i].first;
        const int w = graph[u][i].second;

        if (dist[u] + w < dist[v]) {
          dist[v] = dist[u] + w;
          pq.push({dist[v], v});
        }
      } 
    }

    queue<int> q;
    q.push(n - 1);

    while (!q.empty()) {
      const int u = q.front();
      q.pop();

      for (int i = 0; i < graph[u].size(); ++i) {
        const int v = graph[u][i].first;
        const int w = graph[u][i].second;
        const int idx = edgeIndex[u][i];

        if (dist[u] == dist[v] + w) {
          ans[idx] = true;
          if (v != 0)
            q.push(v);
        }
      }
    }

    return ans;
  }
};