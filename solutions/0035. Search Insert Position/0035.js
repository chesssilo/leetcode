// Time complexity: O(logn)
// Space complexity: O(1)
var searchInsert = function(nums, target) {
  let left = 0;
  let right = nums.length;

  while (left  < right) {
    let mid = left + Math.floor((right - left) / 2);
        
    if (nums[mid] == target)
      return mid;
    
    if (nums[mid] < target)
      left = mid + 1;
    else
      right = mid;
  }
  
  return left;
};