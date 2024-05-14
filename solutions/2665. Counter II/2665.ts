// Time complexity: O(1)
// Space complexity: O(1)
type ReturnObj = {
  increment: () => number;
  decrement: () => number;
  reset: () => number;
};

function createCounter(init: number): ReturnObj {
  let cur = init;
  return {
    increment: () => ++cur,
    decrement: () => --cur,
    reset: () => (cur = init),
  };
}