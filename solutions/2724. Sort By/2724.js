// Time complexity: O(nlogn)
// Space complexity: O(1) 
var sortBy = function(arr, fn) {
    return arr.sort((a, b) => fn(a) - fn(b))
};