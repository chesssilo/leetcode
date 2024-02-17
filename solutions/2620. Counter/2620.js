// Time complexity: O(1)
// Space complexity: O(1)
var createCounter = function(n) {
  return function() {
    return n++;
  };
};