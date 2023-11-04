// Time complexity: O(n + m)
// Space complexity: O(1)
var getLastMoment = function(n, left, right) {
    let ans = 0;
    
    for (let num of left) {
        ans = Math.max(ans, num);
    }
    
    for (let num of right) {
        ans = Math.max(ans, n - num);
    }
    
    return ans;
};