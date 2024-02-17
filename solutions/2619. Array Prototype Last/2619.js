// Time complexity: O(1)
// Space complexity: O(1)
Array.prototype.last = function() {
  return this.length === 0 ? -1 : this[this.length - 1];
};