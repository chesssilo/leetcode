// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  int minimumSubarrayLength(const vector<int>& nums, int k) {
    int ans = nums.size() + 1;
    vector<int> bits(32);
    for (int l = 0, r = 0; r < nums.size(); ++r) {
      update(bits, nums[r], 1);
      while (l <= r && bitsToNum(bits) >= k) {
        ans = min(ans, r - l + 1);
        update(bits, nums[l++], -1);
      }
    }
    return ans != nums.size() + 1 ? ans : -1;
  }
 private:
  void update(vector<int>& bits, int x, int change) {
    for (int i = 0; i < 32; ++i)
      if ((x >> i) & 1)
        bits[i] += change;
  }
    
  int bitsToNum(const vector<int>& bits) {
    int res = 0;

    for (int i = 0; i < 32; ++i)
      if (bits[i])
        res |= 1 << i;

    return res;
  }    
};