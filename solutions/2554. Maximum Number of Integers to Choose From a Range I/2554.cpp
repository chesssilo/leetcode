// Time complexity: O(n+m)
// Space complexity: O(m)
class Solution {
 public:
  int maxCount(const vector<int>& banned, int n, int maxSum) {
    int ans = 0;
    int sum = 0;
    const unordered_set<int> bannedSet{banned.begin(), banned.end()};

    for (int i = 1; i <= n; ++i)
      if (!bannedSet.contains(i) && sum + i <= maxSum) {
        ++ans;
        sum += i;
      }

    return ans;
  }
};