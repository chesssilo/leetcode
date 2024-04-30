// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  int minOperations(const vector<int>& nums, int k) {
    for (const int num : nums)
      k ^= num;

    return __builtin_popcount(k);
  }
};