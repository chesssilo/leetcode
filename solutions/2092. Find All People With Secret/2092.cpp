// Time complexity: O(m(m + n))
// Space complexity: O(m + n)
class Solution {
public:
  vector<int> findAllPeople(int n, const vector<vector<int>>& meetings, int firstPerson) {
    unordered_map<int, vector<pair<int, int>>> graph;

    for (const auto& meeting : meetings) {
      const int x = meeting[0];
      const int y = meeting[1];
      const int t = meeting[2];
      graph[x].emplace_back(t, y);
      graph[y].emplace_back(t, x);
    }

    vector<int> earliest(n, INT_MAX);
    earliest[0] = 0;
    earliest[firstPerson] = 0;
    queue<pair<int, int>> q;
    q.emplace(0, 0);
    q.emplace(firstPerson, 0);

    while(!q.empty()) {
      auto [person, time] = q.front();
      q.pop();
      for (const auto [t, nextPerson] : graph[person])
        if (t >= time && earliest[nextPerson] > t) {
          earliest[nextPerson] = t;
          q.emplace(nextPerson, t);
        }
    }

    vector<int> ans;
    for (int i = 0; i < n; ++i)
      if (earliest[i] != INT_MAX)
        ans.push_back(i);

    return ans;
  }
};