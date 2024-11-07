// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  int minimumArrayLength(const vector<int>& nums) {
    const int minNum = ranges::min(nums);
    
    if (ranges::any_of(nums, [minNum](int num) {return num % minNum > 0; }))
      return 1;

    return (ranges::count(nums, minNum) + 1) / 2;    
  }
};