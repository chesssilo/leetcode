// Time complexity: O(max(promise1 time, promise2 time))
// Space complexity: O(1)
type P = Promise<number>

async function addTwoPromises(promise1: P, promise2: P): P {
  let values = await Promise.all([promise1, promise2]);
  return values[0] + values[1];
};