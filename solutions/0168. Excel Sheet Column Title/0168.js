// Time complexity: O(logn)
// Space complexity: O(logn)
var convertToTitle = function(columnNumber) {
    let ans = '';
        while (columnNumber > 0) {
            columnNumber--;
            ans = String.fromCharCode((columnNumber % 26) + 65) + ans;
            columnNumber = Math.floor(columnNumber / 26);
        }
    return ans;
};