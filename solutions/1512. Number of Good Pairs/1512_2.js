// Time complexity: O(n)
// Space complexity: O(n)
var numIdenticalPairs = function(nums) {
    const counts = new Map();
    let ans = 0;

    for (const num of nums) {
        ans += counts.get(num) || 0;
        counts.set(num, (counts.get(num) || 0) + 1);
    }

    return ans;
};