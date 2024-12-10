// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
 public:
  vector<int> getSneakyNumbers(const vector<int>& nums) {
    vector<bool> flags(nums.size()-2);
    vector<int> ans;
    
    for (const int& num : nums) {
      if (flags[num]) 
        ans.push_back(num);
      flags[num] = true;
    }
    
    return ans;
  }
};