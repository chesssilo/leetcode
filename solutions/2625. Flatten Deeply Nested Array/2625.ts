// Time Complexity: O(n)
// Space Complexity: O(n)
type MultiDimensionalArray = (number | MultiDimensionalArray)[];

let flat = function (
  arr: MultiDimensionalArray,
  n: number
): MultiDimensionalArray {
  function dfs(arr: number | MultiDimensionalArray, n: number) {
    if (typeof arr === 'number') {
      ans.push(arr);
    } else if (n === 0) {
      for (const a of arr) {
        ans.push(a);
      }
    } else {
      for (const a of arr) {
        dfs(a, n - 1);
      }
    }
  }

  const ans: MultiDimensionalArray = [];
  dfs(arr, n);

  return ans;
};