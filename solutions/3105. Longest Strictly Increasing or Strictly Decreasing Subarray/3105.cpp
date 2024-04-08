// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  int longestMonotonicSubarray(const vector<int>& nums) {
    int ans = 1;
    int incLength = 1;
    int decLength = 1;
        
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i] >  nums[i - 1]) {
        ++incLength;
        decLength = 1;
      } else if (nums[i] < nums[i - 1]) {
        ++decLength;
        incLength = 1;
      } else {
        decLength = 1;
        incLength = 1;
      }
      ans = max(ans, max(incLength, decLength));
    }
        
    return ans;
  }
};