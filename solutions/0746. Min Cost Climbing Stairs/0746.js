// Time complexity: O(n)
// Space complexity: O(1)
var minCostClimbingStairs = function(cost) {
    let prev = cost[0];
    let cur = cost[1];

    for (let i = 2; i < cost.length; ++i) {
        let next = cost[i] + Math.min(prev, cur);
        prev = cur;
        cur = next;
    }
    return Math.min(prev, cur);
};