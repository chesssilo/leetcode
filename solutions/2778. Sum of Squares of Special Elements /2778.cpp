// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  int sumOfSquares(const vector<int>& nums) {
    const int n = nums.size();
    int ans = 0;

    for (int i = 0; i < n; ++i)
      if (n % (i + 1) == 0)
        ans += nums[i] * nums[i];

    return ans;
  }
};