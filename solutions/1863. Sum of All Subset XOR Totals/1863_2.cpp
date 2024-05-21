// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  int subsetXORSum(const vector<int>& nums) {
    return accumulate(nums.begin(), nums.end(), 0, bit_or<>()) 
           << nums.size() - 1;
  }
};