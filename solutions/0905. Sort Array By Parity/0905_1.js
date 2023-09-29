// Time complexity: O(n)
// Space complexity: O(n)
var sortArrayByParity = function(nums) {
    const ans = [];
    for (const num of nums) {
        if ((num & 1) === 0) {
            ans.push(num);
        }
    }
    for (const num of nums) {
        if ((num & 1) !== 0) {
            ans.push(num);
        }
    }
    return ans;
};