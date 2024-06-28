// Time complexity: O(1)
// Space complexity: O(1)
class Solution {
 public:
  int findCenter(const vector<vector<int>>& edges) {
    return edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]
            ? edges[0][0] 
            : edges[0][1];
  }
};