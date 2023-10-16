// Time complexity: O(rowIndex^2)
// Space complexity: O(rowIndex)
var getRow = function(rowIndex) {
    let ans = new Array(rowIndex + 1).fill(1);

        for (let i = 2; i <= rowIndex; ++i) {
            for (let j = 1; j < i; ++j) {
                ans[i - j] += ans[i - j - 1];
            }
        }

        return ans;
};