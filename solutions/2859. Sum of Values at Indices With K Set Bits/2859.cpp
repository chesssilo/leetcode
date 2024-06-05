// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  int sumIndicesWithKSetBits(const vector<int>& nums, int k) {
    int ans = 0;

    for (unsigned i = 0; i < nums.size(); ++i)
      if (popcount(i) == k)
        ans += nums[i];

    return ans;
  }
};