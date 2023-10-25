// Time complexity: O(logk)
// Space complexity: O(logk)
var kthGrammar = function(n, k) {
    let count = (k - 1).toString(2).split('0').join('').length;
    return count % 2 === 0 ? 0 : 1;
};