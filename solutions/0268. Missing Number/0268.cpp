// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
  int missingNumber(const vector<int>& nums) {
    int ans = nums.size();

    for (int i = 0; i < nums.size(); ++i) 
      ans ^= i ^ nums[i];

    return ans; 
  }
};