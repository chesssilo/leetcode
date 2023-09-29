// Time complexity: O(n)
// Space complexity: O(1)
var isMonotonic = function(nums) {
    let increasing = true;
    let decreasing = true;

        for (let i = 1; i < nums.length; ++i) {
            increasing &= nums[i] >= nums[i - 1];
            decreasing &= nums[i] <= nums[i - 1];
        }

        return increasing || decreasing;
};