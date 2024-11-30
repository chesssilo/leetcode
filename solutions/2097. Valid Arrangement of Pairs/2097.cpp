// Time complexity: O(V+E)
// Space complexity: O(V+E)
class Solution {
 public:
  vector<vector<int>> validArrangement(const vector<vector<int>>& pairs) {
    vector<vector<int>> ans;
    unordered_map<int, stack<int>> graph;
    unordered_map<int, int> outDegree;
    unordered_map<int, int> inDegrees;

    for (const vector<int>& pair : pairs) {
      const int start = pair[0];
      const int end = pair[1];
      graph[start].push(end);
      ++outDegree[start];
      ++inDegrees[end];
    }

    const int startNode = getStartNode(graph, outDegree, inDegrees, pairs);
    euler(graph, startNode, ans);
    ranges::reverse(ans);
    return ans;
  }

 private:
  int getStartNode(
    const unordered_map<int, stack<int>>& graph,
    unordered_map<int, int>& outDegree,
    unordered_map<int, int>& inDegrees,
    const vector<vector<int>>& pairs
  ) {
    for (const auto& [u, _] : graph)
      if (outDegree[u] - inDegrees[u] == 1)
        return u;
    return pairs[0][0];
  }

  void euler(
    unordered_map<int, stack<int>>& graph, int u, vector<vector<int>>& ans
  ) {
    auto& stack = graph[u];
    while (!stack.empty()) {
      const int v = stack.top();
      stack.pop();
      euler(graph, v, ans);
      ans.push_back({u, v});
    }
  }
};