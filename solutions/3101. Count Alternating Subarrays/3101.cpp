// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  long long countAlternatingSubarrays(const vector<int>& nums) {
    long long ans = 1;
    int size = 1;
    
    for (int i = 1; i < nums.size(); ++i) {
      size = nums[i - 1] == nums[i] ? 1 : size + 1;
      ans += size;
    }
    
    return ans;
  }
};