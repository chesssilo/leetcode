// Time complexity: O(1)
// Space complexity: O(1)
var isReachableAtTime = function(sx, sy, fx, fy, t) {
    let minStep = Math.max(Math.abs(sx - fx), Math.abs(sy - fy));
    return minStep == 0 ? t != 1 : minStep <= t;
}