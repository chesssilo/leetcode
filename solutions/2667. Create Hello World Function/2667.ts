// Time complexity: O(1)
// Space complexity: O(1)
function createHelloWorld() {
  return function(...args): string {
    return 'Hello World';
  };
} 