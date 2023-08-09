// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
  void moveZeroes(vector<int>& nums) {
    int i = 0;
    while ( i < nums.size() && nums[i] != 0) {
      ++i;
    }
    int j = i;
    for ( ; i < nums.size(); ++i) {
      if (nums[i] != 0) {
        nums[j] = nums[i];
        ++j;
      }
    }
    for ( ; j < nums.size(); ++j) {
      nums[j] = 0;
    }
	}	
};