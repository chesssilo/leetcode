// Time complexity: O(logn)
// Space complexity: O(1)
var searchInsert = function(nums, target) {
    let l = 0;
    let r = nums.length;

    while(l < r) {
        let m = l + Math.floor((r - l) / 2);
        if (nums[m] == target) {
            return m;
        }
        if (nums[m] < target) {
            l = m + 1;
        } else {
            r = m;
        }
    }
    return l;
};