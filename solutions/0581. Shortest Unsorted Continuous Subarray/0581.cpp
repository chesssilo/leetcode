// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  int findUnsortedSubarray(const vector<int>& nums) {
    const int n = nums.size();
    int mn = INT_MAX;
    int mx = INT_MIN;
    bool meetDecrease = false;
    bool meetIncrease = false;

    for (int i = 1; i < n; ++i) {
      if (nums[i] < nums[i - 1])
        meetDecrease = true;
      if (meetDecrease)
        mn = min(mn, nums[i]);
    }

    for (int i = n - 2; i >= 0; --i) {
      if (nums[i] > nums[i + 1])
        meetIncrease = true;
      if (meetIncrease)
        mx = max(mx, nums[i]);
    }

    int l = 0;
    while (l < n && nums[l] <= mn) {
      ++l;
    }

    int r = n - 1;
    while (r >= 0 && nums[r] >= mx) {
      --r;
    }

    return l < r ? r - l + 1 : 0;
  }
};