// Time complexity: O(nlog(max(nums)))
// Space complexity: O(1)
class Solution {
 public:
  int minimumSize(const vector<int>& nums, int maxOperations) {
    int l = 1;
    int r = ranges::max(nums);

    while (l < r) {
      const int m = l + (r - l) / 2;
      if (numOperations(nums, m) <= maxOperations)
        r = m;
      else
        l = m + 1;
    }

    return l;
  }

 private:
  int numOperations(const vector<int>& nums, int m) {
    int operations = 0;
    for (const int num : nums)
      operations += (num - 1) / m;
    return operations;
  }
};