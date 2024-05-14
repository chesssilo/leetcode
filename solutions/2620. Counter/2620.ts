// Time complexity: O(1)
// Space complexity: O(1)
function createCounter(n: number): () => number {
  return function() {
    return n++;
  };
}
