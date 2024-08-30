// Time complexity: O(n)
// Space complexity: O(n)
class UnionFind {
 public:
  vector<int> parent;
  int componentCount;
  unordered_set<int> uniqueNodes;

  UnionFind(int n) { 
    parent.resize(n, -1);
    componentCount = 0;
  }

  int find(int node) {
    if (uniqueNodes.find(node) == uniqueNodes.end()) {
      componentCount++;
      uniqueNodes.insert(node);
    }

    if (parent[node] == -1)
      return node;

    return parent[node] = find(parent[node]);
  }

  void unionNodes(int node1, int node2) {
    int root1 = find(node1);
    int root2 = find(node2);

    if (root1 == root2)
      return;

    parent[root1] = root2;
    componentCount--;
  }
};

class Solution {
 public:
  int removeStones(const vector<vector<int>>& stones) {
    UnionFind uf(20002);

    for (int i = 0; i < stones.size(); ++i)
      uf.unionNodes(stones[i][0], stones[i][1] + 10001);

    return stones.size() - uf.componentCount;
  }
};