// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  string findDifferentBinaryString(const vector<string>& nums) {
    string ans;

    for (int i = 0; i < nums.size(); ++i)
      ans += nums[i][i] == '0' ? '1' : '0';
        
    return ans;
  }
};