// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
 public:
  vector<int> singleNumber(const vector<int>& nums) {
    const int xors = accumulate(nums.begin(), nums.end(), 0, bit_xor<>());
    const int lowbit = xors & -static_cast<unsigned int>(xors);
    vector<int> ans(2);

    for (const int num : nums)
      if (num & lowbit)
        ans[0] ^= num;
      else
        ans[1] ^= num;

    return ans;
  }
};