// Time complexity: O(n)
// Space complexity: O(n)
var twoSum = function(nums, target) {
    const numToIndex = new Map();
    for (let i = 0; i < nums.length; i++) {
        if (numToIndex.has(target - nums[i])) {
            return [numToIndex.get(target - nums[i]), i];
        }
        numToIndex.set(nums[i], i);
    }
    return [-1, -1];
};