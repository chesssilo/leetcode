// Time complexity: O(n^2)
// Space complexity: O(1)
class Solution {
 public:
  int minimumSubarrayLength(const vector<int>& nums, int k) {
    int ans = INT_MAX;

    for (int i = 0; i < nums.size(); ++i) {
      int curr = nums[i];
      if (curr >= k)
        return 1;

      for (int j = i + 1; j < nums.size(); ++j) {
        curr |= nums[j];
        if (curr >= k) {
          ans = min(ans, j - i + 1);
          break;
        }
      }
    }

    return ans == INT_MAX ? -1 : ans;
  }
};