// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  int minSwaps(const vector<int>& nums) {
    const int n = nums.size();
    const int k = ranges::count(nums, 1);
    int ones = 0;
    int maxOnes = 0;

    for (int i = 0; i < n * 2; ++i) {
      if (i >= k && nums[(i - k) % n])
        --ones;
      if (nums[i % n])
        ++ones;
      maxOnes = max(maxOnes, ones);
    }

    return k - maxOnes;
  }
};