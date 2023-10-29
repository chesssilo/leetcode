// Time complexity: O(1)
// Space complexity: O(1)
var poorPigs = function(buckets, minutesToDie, minutesToTest) {
    return Math.ceil(Math.log2(buckets) / Math.log2(minutesToTest / minutesToDie + 1));
};