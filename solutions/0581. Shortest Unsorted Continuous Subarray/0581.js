// Time complexity: O(n)
// Space complexity: O(1)
var findUnsortedSubarray = function(nums) {
    let maxi = nums[0];
    let last = -1;

    for (let i = 0; i < nums.length; i++) {
        maxi = Math.max(maxi, nums[i]);
        if (nums[i] < maxi) {
            last = i;
        } 
    }

    if (last === -1) {
        return 0;
    }

    let mini = nums[nums.length - 1];
    let first = -1;
    for (let i = nums.length - 1; i >= 0; i--) {
        mini = Math.min(mini, nums[i]);
        if (nums[i] > mini) {
            first = i;
        }
    }

    return last - first + 1;
};