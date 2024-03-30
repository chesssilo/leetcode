// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  long long countSubarrays(const vector<int>& nums, int k) {
    const int maxNum = ranges::max(nums);
    long long ans = 0;
    int count = 0;

    for (int l = 0, r  = 0; r < nums.size(); ++r) {
      if (nums[r] == maxNum)
        ++count;
      while (count == k)
        if (nums[l++] == maxNum)
          --count;
      ans += l;            
    }

    return ans;
  }
};