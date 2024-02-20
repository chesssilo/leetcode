// Time complexity: O(n)
// Space complexity: O(1)
var missingNumber = function(nums) {
  let ans = nums.length;

  for (let i = 0; i < nums.length; ++i) {
    ans ^= i ^ nums[i];
  }

  return ans;
};