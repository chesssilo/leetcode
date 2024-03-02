// Time complexity: O(logn)
// Space complexity: O(1)
class Solution {
public:
  int searchInsert(const vector<int>& nums, const int target) {
    int left = 0;
    int right = nums.size();

    while (left < right) {
      int mid = left + (right - left) / 2;

      if (nums[mid] == target)
        return mid;
      
      if (nums[mid] < target)
        left = mid + 1;
      else
        right = mid;
    }
    
    return left;
  }
};