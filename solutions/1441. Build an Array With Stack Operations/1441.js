// Time complexity: O(mn)
// Space complexity: O(m)
var buildArray = function(target, n) {
    let ans = [];
    let i = 0;

    for (let num of target) {
      while (i < num - 1) {
        ans.push("Push");
        ans.push("Pop");
        i++;
      }

      ans.push("Push");
      i++;
    }

    return ans;
};