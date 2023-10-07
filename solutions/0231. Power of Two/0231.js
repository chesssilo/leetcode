// Time complexity: O(1)
// Space complexity: O(1)
var isPowerOfTwo = function(n) {
    return n > 0 && (n & (n - 1)) === 0;
};