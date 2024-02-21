// Time complexity: O(1)
// Space complexity: O(1)
var rangeBitwiseAnd = function(left, right) {
  let shiftBits = 0;

  while (left != right) {
    left >>= 1;
    right >>= 1;
    ++shiftBits;
  }

  return left << shiftBits;
};