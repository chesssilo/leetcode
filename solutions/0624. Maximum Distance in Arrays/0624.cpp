// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  int maxDistance(const vector<vector<int>>& arrays) {
    int ans = 0;
    int mn = 10000;
    int mx = -10000;

    for (const vector<int>& arr : arrays) {
      ans = max({ans, arr.back() - mn, mx - arr.front()});
      mn = min(mn, arr.front());
      mx = max(mx, arr.back());
    }

    return ans;
  }
};