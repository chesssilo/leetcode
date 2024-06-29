// Time complexity: O(sort+m)
// Space complexity: O(n)
class Solution {
 public:
  long long maximumImportance(int n, const vector<vector<int>> roads) {
    long ans = 0;
    vector<long> count(n);

    for (const vector<int>& road : roads) {
      ++count[road[0]];
      ++count[road[1]];
    }

    ranges::sort(count);

    for (int i = 0; i < n; ++i)
      ans += (i + 1) * count[i];

    return ans;
  }
};