// Time complexity: O(logn)
// Space complexity: O(1)
var solution = function(isBadVersion) {
    /**
     * @param {integer} n Total versions
     * @return {integer} The first bad version
     */
    return function(n) {
        let good = 0;
        let bad = n;

        while (bad > good + 1) {
            let mid = good + Math.floor((bad - good) / 2);
            if (isBadVersion(mid)) {
                bad = mid;
            } else {
                good = mid;
            }
        }

        return bad;
    };
};