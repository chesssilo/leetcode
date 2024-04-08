// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  bool checkPossibility(const vector<int>& nums) {
    int count = 0;
    int prev = INT_MIN;

    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] < prev) {
        ++count;
        if (count > 1)
          return false;
        if (i > 1 && nums[i - 2] > nums[i])
          continue;
      }
      prev = nums[i];
    }  
    
    return true;
  }
};