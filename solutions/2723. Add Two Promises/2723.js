// Time complexity: O(max(promise1 time, promise2 time))
// Space complexity: O(1)
var addTwoPromises = async function(promise1, promise2) {
  let values = await Promise.all([promise1, promise2]);
  return values[0] + values[1];
};
