// Time complexity: O(n)
// Space complexity: O(n)
var kidsWithCandies = function(candies, extraCandies) {
    let ans = [];
    let maxCandies = 0;
    for (let candy of candies) {
        maxCandies = Math.max(maxCandies, candy);
    }

    for (let candy of candies) {
        ans.push(candy + extraCandies >= maxCandies);
    }
    return ans;
}