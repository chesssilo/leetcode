// Time complexity: O(1)
// Space complexity: O(1)
var isPowerOfThree = function(n) {
    return n > 0 && Math.pow(3, 19) % n === 0;
};